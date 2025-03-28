/*
 * AD8232.c
 *
 *  Created on: Mar 27, 2025
 *      Author: omar
 */

#include "AD8232.h"

ADC_HandleTypeDef *hadc1_AD8232;
DMA_HandleTypeDef *hdma_AD8232;
volatile AD8232_Status_t leadOffStatus = AD8232_OK;
#define ECG_BUFFER_SIZE 100  // Buffer size for peak detection
#define THRESHOLD 2000       // Adjust based on signal characteristics
#define MIN_RR_INTERVAL 300  // Minimum interval between peaks in ms

volatile uint16_t ecgBuffer[ECG_BUFFER_SIZE] = {0};  // DMA buffer for ECG data
volatile uint32_t lastPeakTime = 0;  // Timestamp of last R-peak
volatile uint16_t heartRate = 0;  // Calculated BPM

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == LOPL_pin || GPIO_Pin == LONE_pin) {
        // If any lead is disconnected, set status to ERROR
        if (HAL_GPIO_ReadPin(LO_port, LOPL_pin) == GPIO_PIN_SET ||
            HAL_GPIO_ReadPin(LO_port, LONE_pin) == GPIO_PIN_SET) {
            leadOffStatus = AD8232_ERROR;  // Lead is OFF
        } else {
            leadOffStatus = AD8232_OK;  // Leads are ON
        }
    }
}

// AD8232 Functions
AD8232_Status_t AD8232_Init(DMA_HandleTypeDef *DMAAD){
	if(DMAAD==NULL)return AD8232_ERROR;
	hdma_AD8232=DMAAD;
	HAL_ADC_Start_DMA(hadc1_AD8232, (uint32_t*)ecgBuffer, ECG_BUFFER_SIZE);
	return AD8232_OK;
}
uint16_t *AD8232_ReadECG(void){
	return ecgBuffer;
}
AD8232_Status_t AD8232_CheckLeadOff(void){
	return leadOffStatus;
}
uint16_t AD8232_GetHeartRate(void){
	return heartRate;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if (hadc->Instance==hadc1_AD8232->Instance) {
		static uint16_t PreValue=0;

		for (uint16_t var = 0; var < ECG_BUFFER_SIZE; ++var) {
			uint16_t CV=ecgBuffer[var];
			uint32_t CT=HAL_GetTick();
			if (CV > THRESHOLD && PreValue < THRESHOLD) {
				if ((CT - lastPeakTime) > MIN_RR_INTERVAL) {
					uint32_t RR_Interval = CT - lastPeakTime;
					lastPeakTime = CT;

					// Compute heart rate (BPM)
					heartRate = 60000 / RR_Interval;
				}
			}
			 PreValue=CV;
		}
		// Restart ADC DMA for continuous acquisition
		HAL_ADC_Start_DMA(hadc1_AD8232, (uint32_t*)ecgBuffer, ECG_BUFFER_SIZE);
	}
}
