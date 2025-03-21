/*
 * AED7753.h
 *
 *  Created on: Mar 19, 2025
 *      Author: omar
 */

#ifndef ADE7953_H
#define ADE7953_H

#include "main.h"  // Change this to match your STM32 series

#define ADE7953_I2C_ADDRESS  0x38  // Default 7-bit I2C address

// ADE7953 Register Addresses
#define ADE7953_REG_VRMS     0x31  // Voltage RMS
#define ADE7953_REG_IRMSA    0x32  // Current RMS (Channel A)
#define ADE7953_REG_WATT     0x30  // Active Power
#define ADE7953_REG_PF       0x46  // Power Factor
#define ADE7953_REG_ENERGY   0x31  // Energy Register

// Function Prototypes
HAL_StatusTypeDef ADE7953_WriteRegister(I2C_HandleTypeDef *hi2c, uint8_t reg, uint32_t value, uint8_t size);
HAL_StatusTypeDef ADE7953_ReadRegister(I2C_HandleTypeDef *hi2c, uint8_t reg, uint32_t *value, uint8_t size);
HAL_StatusTypeDef ADE7953_Reset(I2C_HandleTypeDef *hi2c);

#endif // ADE7953_H
