/*
 * SSD1306.h
 *
 *  Created on: Mar 19, 2025
 *      Author: omar
 */

#ifndef SSD1306_H_
#define SSD1306_H_


#include "main.h"  // Change based on your STM32 series
#include <string.h>

// OLED I2C Address
#define SSD1306_I2C_ADDR  0x3C

// Function Prototypes
void SSD1306_Init(I2C_HandleTypeDef *hi2c);
void SSD1306_Clear(void);
void SSD1306_SetCursor(uint8_t x, uint8_t y);
void SSD1306_Print(char *str);
void SSD1306_UpdateScreen(void);


#endif /* SSD1306_H_ */
