################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sensors/AD8232.c \
../Sensors/HC-05.c 

OBJS += \
./Sensors/AD8232.o \
./Sensors/HC-05.o 

C_DEPS += \
./Sensors/AD8232.d \
./Sensors/HC-05.d 


# Each subdirectory must supply rules for building sources it contributes
Sensors/%.o Sensors/%.su Sensors/%.cyclo: ../Sensors/%.c Sensors/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Projecrs/New folder/Sensors" -I"E:/Projecrs/New folder/FreeRtos" -I"E:/Projecrs/New folder/FreeRtos/Source" -I"E:/Projecrs/New folder/FreeRtos/Source/include" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/GCC/ARM_CM4F" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Sensors

clean-Sensors:
	-$(RM) ./Sensors/AD8232.cyclo ./Sensors/AD8232.d ./Sensors/AD8232.o ./Sensors/AD8232.su ./Sensors/HC-05.cyclo ./Sensors/HC-05.d ./Sensors/HC-05.o ./Sensors/HC-05.su

.PHONY: clean-Sensors

