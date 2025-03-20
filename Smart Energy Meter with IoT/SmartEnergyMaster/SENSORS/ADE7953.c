/*
 * ADE7953.c
 *
 *  Created on: Mar 19, 2025
 *      Author: omar
 */

#include "ADE7953.h"

HAL_StatusTypeDef ADE7953_WriteRegister(I2C_HandleTypeDef *hi2c, uint8_t reg, uint32_t value, uint8_t size){
    if (!hi2c) return HAL_ERROR;

    uint8_t data[4];  // Buffer for up to 32-bit value

    // Convert 32-bit value to byte array (Big-Endian format)
    for (uint8_t i = 0; i < size; i++) {
        data[i] = (value >> (8 * (size - 1 - i))) & 0xFF;
    }

    return HAL_I2C_Mem_Write(hi2c, ADE7953_I2C_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT, data, size, 100);
}
HAL_StatusTypeDef ADE7953_ReadRegister(I2C_HandleTypeDef *hi2c, uint8_t reg, uint32_t *value, uint8_t size) {
    if (!hi2c || !value) return HAL_ERROR;

    uint8_t data[4] = {0};  // Buffer for up to 32-bit data

    // Read data from ADE7953 register
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hi2c, ADE7953_I2C_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT, data, size, 100);
    if (status != HAL_OK) return status;

    // Convert received data (Big-Endian) to 32-bit integer
    *value = 0;
    for (uint8_t i = 0; i < size; i++) {
        *value |= (uint32_t)data[i] << (8 * (size - 1 - i));
    }

    return HAL_OK;
}
HAL_StatusTypeDef ADE7953_Reset(I2C_HandleTypeDef *hi2c) {
    if (!hi2c) return HAL_ERROR;

    uint8_t regAddr = 0x00;  // Reset register
    uint8_t resetCmd = 0x01; // Reset command

    return HAL_I2C_Mem_Write(hi2c, ADE7953_I2C_ADDRESS << 1, regAddr, I2C_MEMADD_SIZE_8BIT, &resetCmd, 1, 100);
}
