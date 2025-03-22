################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/Source/portable/MemMang/heap_4.c 

OBJS += \
./FreeRtos/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRtos/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/Source/portable/MemMang/%.o FreeRtos/Source/portable/MemMang/%.su FreeRtos/Source/portable/MemMang/%.cyclo: ../FreeRtos/Source/portable/MemMang/%.c FreeRtos/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/Sensor" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/include" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/portable/GCC/ARM_CM4F" -I"E:/Projecrs/Multi-Sensor Fusion for Autonomous Navigation/navigation/FreeRtos/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRtos-2f-Source-2f-portable-2f-MemMang

clean-FreeRtos-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./FreeRtos/Source/portable/MemMang/heap_4.cyclo ./FreeRtos/Source/portable/MemMang/heap_4.d ./FreeRtos/Source/portable/MemMang/heap_4.o ./FreeRtos/Source/portable/MemMang/heap_4.su

.PHONY: clean-FreeRtos-2f-Source-2f-portable-2f-MemMang

