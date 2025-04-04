/*
 * UltraSonic.c
 *
 *  Created on: Mar 22, 2025
 *      Author: omar
 */

#include "UltraSonic.h"

QueueHandle_t ultrasonicQueue;
TIM_HandleTypeDef *htim_ultrasonic;
uint32_t IC_Val1 = 0, IC_Val2 = 0;
uint8_t Is_First_Captured = 0;
uint32_t Difference = 0;
float Distance = 0;
void HCSR04_Init(TIM_HandleTypeDef *htim){
	 htim_ultrasonic=htim;
	 HAL_TIM_IC_Start(htim_ultrasonic,TIM_CHANNEL_1 );
}
void HCSR04_Trigger(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	vTaskDelay(pdMS_TO_TICKS(1));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){
		if(!Is_First_Captured){
			IC_Val1=HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			Is_First_Captured=1;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_FALLING);
		}else{
			IC_Val2=HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			Is_First_Captured = 0;
			Difference=(IC_Val2>IC_Val1)?(IC_Val2-IC_Val1):(0xFFFF-IC_Val1)+IC_Val2;
			Distance=(float)(Difference*.017);
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			xQueueSendFromISR(ultrasonicQueue, &Distance, NULL);
		}
	}
}

// FreeRTOS Task Prototypes
void Ultrasonic_Task(void *pvParameters){
	float dis;
	while(1){
		HCSR04_Trigger();
		vTaskDelay(pdMS_TO_TICKS(100));
		if(xQueueReceive(ultrasonicQueue, &dis, pdMS_TO_TICKS(100))==pdTRUE){

		}
	}
}

void Ultrasonic_Start(void){
	xQueueCreate(ultrasonicQueue,sizeof(float));
	xTaskCreate(Ultrasonic_Task, "Ultrasonic Task", 200, NULL, 2, NULL);
}
