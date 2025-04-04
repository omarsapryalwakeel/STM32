/*
 * LoRA.c
 *
 *  Created on: Mar 25, 2025
 *      Author: omar
 */


#include "LoRA.h"

SPI_HandleTypeDef *SX1278_SPI;

void SX1278_Init(SPI_HandleTypeDef *spi){
	SX1278_SPI=spi;
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(10);
	SX1278_SetMode(LORA_MODE_STDBY);
}

void SX1278_SetFrequency(uint32_t frequency){
	uint32_t FStep=32000000/524288;
	uint32_t FRF=frequency/FStep;
	SX1278_WriteRegister(REG_FRF_MSB,(FRF>>16)&0xFF);
	SX1278_WriteRegister(REG_FRF_MID,(FRF>>8)&0xFF);
	SX1278_WriteRegister(REG_FRF_LSB,FRF&0xFF);
}
void SX1278_SetTxPower(uint8_t power, uint8_t usePA_BOOST) {
    if (usePA_BOOST) {
        // PA_BOOST mode (higher power output)
        SX1278_WriteRegister(REG_PA_CONFIG, 0x80 | (power & 0x0F));
    } else {
        // RFO mode (lower power output)
        SX1278_WriteRegister(REG_PA_CONFIG, 0x70 | (power & 0x0F));
    }
}
void SX1278_SendPacket(uint8_t *data, uint8_t length){
	SX1278_SetMode(LORA_MODE_STDBY);
	SX1278_WriteRegister(REG_FIFO_ADDR_PTR, 0x00);
	int i;
	for ( i = 0;  i <length ; ++ i) {
		SX1278_WriteRegister(0x00, data[i]);
	}
	SX1278_WriteRegister(REG_PAYLOAD_LENGTH, length);
	SX1278_SetMode(LORA_MODE_TX);
	while((SX1278_ReadRegister(REG_IRQ_FLAGS)&0x8)==0);
	SX1278_WriteRegister(REG_IRQ_FLAGS, 0x08);

}
uint8_t SX1278_ReceivePacket(uint8_t *buffer, uint8_t maxLength){
	SX1278_SetMode(LORA_MODE_RX);
	while((SX1278_ReadRegister(REG_IRQ_FLAGS)&40)==0);
	uint8_t length=SX1278_ReadRegister(REG_RX_NB_BYTES);
	if(length>maxLength)length=maxLength;
	SX1278_WriteRegister(REG_FIFO_ADDR_PTR, SX1278_ReadRegister(REG_FIFO_RX_CURRENT));
	for (int i = 0; i < length; ++i) {
		buffer[i]=SX1278_ReadRegister(0x00);
	}
	SX1278_WriteRegister(REG_IRQ_FLAGS, 0x40);
	    return length;
}
uint8_t SX1278_CheckRSSI(void){
	return SX1278_ReadRegister(REG_PKT_RSSI_VALUE);
}
void SX1278_SetMode(uint8_t mode){
	SX1278_WriteRegister(REG_OP_MODE, mode&0x07);
}
uint8_t SX1278_ReadRegister(uint8_t reg){
	uint8_t value;
	uint8_t Bufer=(reg&0x7F);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_SPI_Transmit(SX1278_SPI, &Bufer, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive(SX1278_SPI, &value, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	return value;

}
void SX1278_WriteRegister(uint8_t reg, uint8_t value){
	uint8_t Buffer[]={reg|0x80,value};
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_SPI_Transmit(SX1278_SPI, Buffer, 2, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}
