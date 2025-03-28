/*
 * HC-05.c
 *
 *  Created on: Mar 26, 2025
 *      Author: omar
 */

#include "HC-05.h"

UART_HandleTypeDef *HC05_UART;

// HC-05 Initialization
void HC05_Init(UART_HandleTypeDef *UART){
	HC05_UART=UART;
	HAL_GPIO_WritePin(HC_05EN_GPIO_Port, HC_05EN_Pin, GPIO_PIN_RESET);
}
HC05_Status_t HC05_Reset(void){
	HC05_EnterCommandMode();
	const char Buffer[]="AT+RESET\r\n";
	if(HAL_UART_Transmit(HC05_UART,(uint8_t*)Buffer , strlen(Buffer), HAL_MAX_DELAY)!=HAL_OK){
		return HC05_ERROR;
	}
	HC05_ExitCommandMode();
	return HC05_OK;
}
HC05_Status_t HC05_SetBaudRate(uint32_t baudrate){
	HC05_EnterCommandMode();
	char Buffer[50];
	sprintf(Buffer,"AT+UART=%lu,0,0\r\n",baudrate);
	if(HAL_UART_Transmit(HC05_UART,(uint8_t*)Buffer , strlen(Buffer), HAL_MAX_DELAY)!=HAL_OK){
		return HC05_ERROR;
	}
	HC05_ExitCommandMode();
	return HC05_OK;
}
HC05_Status_t HC05_EnterCommandMode(void){
	HAL_GPIO_WritePin(HC_05EN_GPIO_Port, HC_05EN_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
	return HC05_OK;
}
HC05_Status_t HC05_ExitCommandMode(void){
	HAL_GPIO_WritePin(HC_05EN_GPIO_Port, HC_05EN_Pin, GPIO_PIN_RESET);
	HAL_Delay(100);
	return HC05_OK;
}

// HC-05 Data Transmission
HC05_Status_t HC05_SendString(const char *str){
	if(str==NULL)return HC05_ERROR;
	if(HC05_CheckConnection()!=HC05_CONNECTED)return HC05_NOT_CONNECTED;
	HC05_ExitCommandMode();
	HAL_UART_Transmit(HC05_UART, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
	return HC05_OK;
}
HC05_Status_t HC05_SendData(uint8_t *data, uint16_t size){
	if(data==NULL)return HC05_ERROR;
	if(HC05_CheckConnection()!=HC05_CONNECTED)return HC05_NOT_CONNECTED;
	HC05_ExitCommandMode();

	HAL_UART_Transmit(HC05_UART, data, size, HAL_MAX_DELAY);
	return HC05_OK;
}
HC05_Status_t HC05_ReceiveData(uint8_t *buffer, uint16_t size){
	if(buffer==NULL)return HC05_ERROR;
	if(HC05_CheckConnection()!=HC05_CONNECTED)return HC05_NOT_CONNECTED;
	HC05_ExitCommandMode();
	HAL_UART_Receive(HC05_UART, buffer, size, HAL_MAX_DELAY);
	return HC05_OK;

}
HC05_Status_t HC05_CheckConnection(void){
	if (HAL_GPIO_ReadPin(HC_05States_GPIO_Port, HC_05States_Pin)==GPIO_PIN_SET) return HC05_CONNECTED;
	const char Cmd[]="AT\r\n";
	HC05_EnterCommandMode();
	uint8_t response[10] = {0};
	if((HAL_UART_Transmit(HC05_UART, (uint8_t*)Cmd, strlen(Cmd), HAL_MAX_DELAY))!=HAL_OK)return HC05_ERROR;
	if(HAL_UART_Receive(HC05_UART, response, 10, HAL_MAX_DELAY)==HAL_OK){
		if(strstr((char *)response, "OK") != NULL){
			HC05_ExitCommandMode();
			return HC05_CONNECTED;
		}
	}
	HC05_ExitCommandMode();
	return HC05_NOT_CONNECTED;
}

// HC-05 AT Commands
HC05_Status_t HC05_SetName(const char *name){
	if(name==NULL)return HC05_NAME_SET_ERROR;
	HC05_EnterCommandMode();
	char CMD[30];
	uint8_t Respond[10];
	if(strlen(name)>=20) return HC05_NAME_SET_ERROR;

	sprintf(CMD,"AT+NAME=%s\r\n",name);
	if(HAL_UART_Transmit(HC05_UART, (uint8_t*)CMD, strlen(CMD), HAL_MAX_DELAY)==HAL_OK){
		if(HAL_UART_Receive(HC05_UART, Respond, 10, HAL_MAX_DELAY)==HAL_OK){
			if(strstr((char*)Respond,"OK")!=NULL){
				HC05_ExitCommandMode();
				return HC05_OK;
			}
		}
	}
	HC05_ExitCommandMode();
	return HC05_NAME_SET_ERROR;
}
HC05_Status_t HC05_SetPin(const char *pin){
	if(pin==NULL)return HC05_PIN_SET_ERROR;
		HC05_EnterCommandMode();
		char CMD[30];
		uint8_t Respond[10];
		if(strlen(pin)>=20) return HC05_PIN_SET_ERROR;

		sprintf(CMD,"AT+PSWD=%s\r\n",pin);
		if(HAL_UART_Transmit(HC05_UART, (uint8_t*)CMD, strlen(CMD), HAL_MAX_DELAY)==HAL_OK){
			if(HAL_UART_Receive(HC05_UART, Respond, 10, HAL_MAX_DELAY)==HAL_OK){
				if(strstr((char*)Respond,"OK")!=NULL){
					HC05_ExitCommandMode();
					return HC05_OK;
				}
			}
		}
		HC05_ExitCommandMode();
		return HC05_PIN_SET_ERROR;
}

HC05_Status_t HC05_SetRole(uint8_t role)  // 0 = Slave, 1 = Master
{
    if (role != 0 && role != 1 && role!=2) return HC05_ROLE_SET_ERROR;  // Validate role

    HC05_EnterCommandMode(); // Enter AT command mode

    char CMD[20]; // Enough for "AT+ROLE=x\r\n"
    uint8_t Respond[20] = {0}; // Buffer for response

    sprintf(CMD, "AT+ROLE=%d\r\n", role);

    // Send command
    if (HAL_UART_Transmit(HC05_UART, (uint8_t*)CMD, strlen(CMD), HAL_MAX_DELAY) == HAL_OK) {
        // Receive response
        if (HAL_UART_Receive(HC05_UART, Respond, sizeof(Respond), HAL_MAX_DELAY) == HAL_OK) {
            // Check if response contains "OK"
            if (strstr((char*)Respond, "OK") != NULL) {
                HC05_ExitCommandMode(); // Exit AT mode
                return HC05_OK;
            }
        }
    }

    HC05_ExitCommandMode(); // Ensure exit from AT mode
    return HC05_ROLE_SET_ERROR; // Role setting failed
}

HC05_Status_t HC05_BindDevice(const char *address){
	if(address==NULL)return HC05_ERROR;
		HC05_EnterCommandMode();
		char CMD[50];
		uint8_t Respond[30]={0};
		if(strlen(address)>=15) return HC05_ERROR;

		sprintf(CMD,"AT+BIND=%s\r\n",address);
		if(HAL_UART_Transmit(HC05_UART, (uint8_t*)CMD, strlen(CMD), HAL_MAX_DELAY)==HAL_OK){
			if(HAL_UART_Receive(HC05_UART, Respond, 10, HAL_MAX_DELAY)==HAL_OK){
				if(strstr((char*)Respond,"OK")!=NULL){
					HC05_ExitCommandMode();
					return HC05_OK;
				}
			}
		}
	HC05_ExitCommandMode();
	return HC05_ERROR;
}
HC05_Status_t HC05_SetDiscoverable(uint8_t enable){
			HC05_EnterCommandMode();
			char CMD[50];
			uint8_t Respond[30]={0};
			if (enable) {
				sprintf(CMD,"AT+CLASS=0x1F00\r\n");
			} else {
				sprintf(CMD,"AT+CLASS=0x0000\r\n");
			}


			if(HAL_UART_Transmit(HC05_UART, (uint8_t*)CMD, strlen(CMD), HAL_MAX_DELAY)==HAL_OK){
				if(HAL_UART_Receive(HC05_UART, Respond, 10, HAL_MAX_DELAY)==HAL_OK){
					if(strstr((char*)Respond,"OK")!=NULL){
						HC05_ExitCommandMode();
						return HC05_OK;
					}
				}
			}
		HC05_ExitCommandMode();
		return HC05_ERROR;
}
