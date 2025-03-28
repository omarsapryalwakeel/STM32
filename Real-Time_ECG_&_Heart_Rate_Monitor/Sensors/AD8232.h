/*
 * AD8232.h
 *
 *  Created on: Mar 27, 2025
 *      Author: omar
 */

#ifndef AD8232_H_
#define AD8232_H_
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "gpio.h"

extern ADC_HandleTypeDef *hadc1_AD8232;
extern DMA_HandleTypeDef *hdma_AD8232;
#define LOPL_pin		GPIO_PIN_1
#define LONE_pin		GPIO_PIN_2
#define LO_port		GPIOA
typedef enum {
    AD8232_OK = 0,
    AD8232_NO_SIGNAL,
    AD8232_LEAD_OFF,
	AD8232_ERROR

} AD8232_Status_t;

// AD8232 Functions
AD8232_Status_t AD8232_Init(DMA_HandleTypeDef *DMAAD);
uint16_t *AD8232_ReadECG(void);
AD8232_Status_t AD8232_CheckLeadOff(void);
uint16_t AD8232_GetHeartRate(void);

#endif /* AD8232_H_ */
