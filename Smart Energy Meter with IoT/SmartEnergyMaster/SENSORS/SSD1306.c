/*
 * SSD1306.c
 *
 *  Created on: Mar 19, 2025
 *      Author: omar
 */


#include "ssd1306.h"

static I2C_HandleTypeDef *oled_i2c;

void SSD1306_WriteCommand(uint8_t command) {
    uint8_t data[2] = {0x00, command};
    HAL_I2C_Master_Transmit(oled_i2c, SSD1306_I2C_ADDR << 1, data, 2, 100);
}

void SSD1306_Init(I2C_HandleTypeDef *hi2c) {
    oled_i2c = hi2c;
    HAL_Delay(100);

    SSD1306_WriteCommand(0xAE);  // Display off
    SSD1306_WriteCommand(0x20);  // Set Memory Addressing Mode
    SSD1306_WriteCommand(0x10);  // Page Addressing Mode
    SSD1306_WriteCommand(0xB0);  // Set Page Start Address
    SSD1306_WriteCommand(0xC8);  // COM Output Scan Direction
    SSD1306_WriteCommand(0x00);  // Set lower column address
    SSD1306_WriteCommand(0x10);  // Set higher column address
    SSD1306_WriteCommand(0x40);  // Start line address
    SSD1306_WriteCommand(0x81);  // Contrast control
    SSD1306_WriteCommand(0xFF);
    SSD1306_WriteCommand(0xA1);  // Segment remap
    SSD1306_WriteCommand(0xA6);  // Normal display
    SSD1306_WriteCommand(0xA8);  // Set Multiplex Ratio
    SSD1306_WriteCommand(0x3F);
    SSD1306_WriteCommand(0xA4);  // Entire display ON
    SSD1306_WriteCommand(0xD3);  // Set Display Offset
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xD5);  // Set Display Clock Divide Ratio
    SSD1306_WriteCommand(0xF0);
    SSD1306_WriteCommand(0xD9);  // Set Precharge Period
    SSD1306_WriteCommand(0x22);
    SSD1306_WriteCommand(0xDA);  // Set COM Pins Hardware Configuration
    SSD1306_WriteCommand(0x12);
    SSD1306_WriteCommand(0xDB);  // Set VCOMH
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x8D);  // Enable Charge Pump Regulator
    SSD1306_WriteCommand(0x14);
    SSD1306_WriteCommand(0xAF);  // Display ON
}

void SSD1306_Clear(void) {
    uint8_t buffer[1024] = {0};
    HAL_I2C_Mem_Write(oled_i2c, SSD1306_I2C_ADDR << 1, 0x40, I2C_MEMADD_SIZE_8BIT, buffer, 1024, 1000);
}

void SSD1306_SetCursor(uint8_t x, uint8_t y) {
    SSD1306_WriteCommand(0xB0 + y);
    SSD1306_WriteCommand(x & 0x0F);
    SSD1306_WriteCommand(0x10 | (x >> 4));
}

void SSD1306_Print(char *str) {
    while (*str) {
        HAL_I2C_Master_Transmit(oled_i2c, SSD1306_I2C_ADDR << 1, (uint8_t *)str++, 1, 100);
    }
}
