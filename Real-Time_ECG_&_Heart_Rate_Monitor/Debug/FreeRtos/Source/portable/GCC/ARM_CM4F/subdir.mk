################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./FreeRtos/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./FreeRtos/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/Source/portable/GCC/ARM_CM4F/%.o FreeRtos/Source/portable/GCC/ARM_CM4F/%.su FreeRtos/Source/portable/GCC/ARM_CM4F/%.cyclo: ../FreeRtos/Source/portable/GCC/ARM_CM4F/%.c FreeRtos/Source/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Projecrs/New folder/Sensors" -I"E:/Projecrs/New folder/FreeRtos" -I"E:/Projecrs/New folder/FreeRtos/Source" -I"E:/Projecrs/New folder/FreeRtos/Source/include" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/GCC/ARM_CM4F" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRtos-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

clean-FreeRtos-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./FreeRtos/Source/portable/GCC/ARM_CM4F/port.cyclo ./FreeRtos/Source/portable/GCC/ARM_CM4F/port.d ./FreeRtos/Source/portable/GCC/ARM_CM4F/port.o ./FreeRtos/Source/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-FreeRtos-2f-Source-2f-portable-2f-GCC-2f-ARM_CM4F

