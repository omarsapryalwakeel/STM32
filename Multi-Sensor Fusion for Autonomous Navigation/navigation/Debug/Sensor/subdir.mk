################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sensor/MPU6050.c \
../Sensor/UltraSonic.c 

OBJS += \
./Sensor/MPU6050.o \
./Sensor/UltraSonic.o 

C_DEPS += \
./Sensor/MPU6050.d \
./Sensor/UltraSonic.d 


# Each subdirectory must supply rules for building sources it contributes
Sensor/%.o Sensor/%.su Sensor/%.cyclo: ../Sensor/%.c Sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/Sensor" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/include" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/portable/GCC/ARM_CM4F" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Sensor

clean-Sensor:
	-$(RM) ./Sensor/MPU6050.cyclo ./Sensor/MPU6050.d ./Sensor/MPU6050.o ./Sensor/MPU6050.su ./Sensor/UltraSonic.cyclo ./Sensor/UltraSonic.d ./Sensor/UltraSonic.o ./Sensor/UltraSonic.su

.PHONY: clean-Sensor

