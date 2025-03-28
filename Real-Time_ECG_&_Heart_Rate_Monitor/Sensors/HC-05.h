/*
 * HC-05.h
 *
 *  Created on: Mar 26, 2025
 *      Author: omar
 */

#ifndef HC_05_H_
#define HC_05_H_

#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "usart.h"
#include <stdint.h>
#include <string.h>

// Define the UART interface for HC-05
extern UART_HandleTypeDef *HC05_UART;

// HC-05 Status Flags
typedef enum {
    HC05_OK = 0,              // Operation successful
    HC05_ERROR,               // General error
    HC05_TIMEOUT,             // Timeout occurred
    HC05_NOT_CONNECTED,       // Bluetooth is not connected
    HC05_CONNECTED,           // Bluetooth is connected
    HC05_INVALID_RESPONSE,    // Received an unexpected response
    HC05_BUFFER_OVERFLOW,     // Buffer overflow in received data
    HC05_CMD_MODE_FAILED,     // Failed to enter AT command mode
    HC05_DATA_MODE_FAILED,    // Failed to exit AT command mode
    HC05_BAUDRATE_ERROR,      // Failed to set baud rate
    HC05_NAME_SET_ERROR,      // Failed to set device name
    HC05_PIN_SET_ERROR,       // Failed to set pairing PIN
    HC05_ROLE_SET_ERROR,      // Failed to set master/slave mode
    HC05_BIND_ERROR,          // Failed to bind to a device
    HC05_DISCOVERABLE_ERROR   // Failed to make device discoverable
} HC05_Status_t;


// HC-05 Initialization
void HC05_Init(UART_HandleTypeDef *UART);
HC05_Status_t HC05_Reset(void);
HC05_Status_t HC05_SetBaudRate(uint32_t baudrate);
HC05_Status_t HC05_EnterCommandMode(void);
HC05_Status_t HC05_ExitCommandMode(void);

// HC-05 Data Transmission
HC05_Status_t HC05_SendString(const char *str);
HC05_Status_t HC05_SendData(uint8_t *data, uint16_t size);
HC05_Status_t HC05_ReceiveData(uint8_t *buffer, uint16_t size);
HC05_Status_t HC05_CheckConnection(void);

// HC-05 AT Commands
HC05_Status_t HC05_SetName(const char *name);
HC05_Status_t HC05_SetPin(const char *pin);
HC05_Status_t HC05_SetRole(uint8_t role);  // 0 = Slave, 1 = Master
HC05_Status_t HC05_BindDevice(const char *address);
HC05_Status_t HC05_SetDiscoverable(uint8_t enable);

#endif /* HC_05_H_ */
