/*
 * UltraSonic.h
 *
 *  Created on: Mar 22, 2025
 *      Author: omar
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#include "main.h"
#include "gpio.h"
#include "tim.h"

extern QueueHandle_t ultrasonicQueue;
// Function Prototypes
void HCSR04_Init(TIM_HandleTypeDef *htim);
void HCSR04_Trigger(void);
uint32_t HCSR04_Read(void);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

// FreeRTOS Task Prototypes
void Ultrasonic_Task(void *pvParameters);
void Ultrasonic_Start(void);
#endif /* ULTRASONIC_H_ */
