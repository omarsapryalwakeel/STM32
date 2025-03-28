################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/Source/croutine.c \
../FreeRtos/Source/event_groups.c \
../FreeRtos/Source/list.c \
../FreeRtos/Source/queue.c \
../FreeRtos/Source/stream_buffer.c \
../FreeRtos/Source/tasks.c \
../FreeRtos/Source/timers.c 

OBJS += \
./FreeRtos/Source/croutine.o \
./FreeRtos/Source/event_groups.o \
./FreeRtos/Source/list.o \
./FreeRtos/Source/queue.o \
./FreeRtos/Source/stream_buffer.o \
./FreeRtos/Source/tasks.o \
./FreeRtos/Source/timers.o 

C_DEPS += \
./FreeRtos/Source/croutine.d \
./FreeRtos/Source/event_groups.d \
./FreeRtos/Source/list.d \
./FreeRtos/Source/queue.d \
./FreeRtos/Source/stream_buffer.d \
./FreeRtos/Source/tasks.d \
./FreeRtos/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/Source/%.o FreeRtos/Source/%.su FreeRtos/Source/%.cyclo: ../FreeRtos/Source/%.c FreeRtos/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/Projecrs/New folder/Sensors" -I"E:/Projecrs/New folder/FreeRtos" -I"E:/Projecrs/New folder/FreeRtos/Source" -I"E:/Projecrs/New folder/FreeRtos/Source/include" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/GCC/ARM_CM4F" -I"E:/Projecrs/New folder/FreeRtos/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRtos-2f-Source

clean-FreeRtos-2f-Source:
	-$(RM) ./FreeRtos/Source/croutine.cyclo ./FreeRtos/Source/croutine.d ./FreeRtos/Source/croutine.o ./FreeRtos/Source/croutine.su ./FreeRtos/Source/event_groups.cyclo ./FreeRtos/Source/event_groups.d ./FreeRtos/Source/event_groups.o ./FreeRtos/Source/event_groups.su ./FreeRtos/Source/list.cyclo ./FreeRtos/Source/list.d ./FreeRtos/Source/list.o ./FreeRtos/Source/list.su ./FreeRtos/Source/queue.cyclo ./FreeRtos/Source/queue.d ./FreeRtos/Source/queue.o ./FreeRtos/Source/queue.su ./FreeRtos/Source/stream_buffer.cyclo ./FreeRtos/Source/stream_buffer.d ./FreeRtos/Source/stream_buffer.o ./FreeRtos/Source/stream_buffer.su ./FreeRtos/Source/tasks.cyclo ./FreeRtos/Source/tasks.d ./FreeRtos/Source/tasks.o ./FreeRtos/Source/tasks.su ./FreeRtos/Source/timers.cyclo ./FreeRtos/Source/timers.d ./FreeRtos/Source/timers.o ./FreeRtos/Source/timers.su

.PHONY: clean-FreeRtos-2f-Source

