/*
 * MPU6050.h
 *
 *  Created on: Mar 21, 2025
 *      Author: omar
 */

#ifndef MPU6050_H_
#define MPU6050_H_

#include "main.h"
typedef struct{
	int16_t AccelX, AccelY, AccelZ;
	    int16_t GyroX, GyroY, GyroZ;
	    float Temperature;
}MPU6050Data;
extern QueueHandle_t MPU6050Queue;
#define MPU6050_ADDR 0x68 << 1  // Default I2C address (shifted for HAL)
#define WHO_AM_I_REG 0x75       // WHO_AM_I register address

// MPU6050 Function Prototypes
HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef MPU6050_Read_Accel(int16_t *AccelX, int16_t *AccelY, int16_t *AccelZ);
HAL_StatusTypeDef MPU6050_Read_Gyro( int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);
HAL_StatusTypeDef MPU6050_Read_Temp( float *Temperature);
HAL_StatusTypeDef MPU6050_Read_All( int16_t *AccelX, int16_t *AccelY, int16_t *AccelZ,
                                   int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ, float *Temperature);

void TaskMPU6050(void *vPR);
void MPU6050_init_task();


#endif /* MPU6050_H_ */
