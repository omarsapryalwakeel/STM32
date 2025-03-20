################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SENSORS/ADE7953.c \
../SENSORS/ESP8266.c \
../SENSORS/SSD1306.c 

OBJS += \
./SENSORS/ADE7953.o \
./SENSORS/ESP8266.o \
./SENSORS/SSD1306.o 

C_DEPS += \
./SENSORS/ADE7953.d \
./SENSORS/ESP8266.d \
./SENSORS/SSD1306.d 


# Each subdirectory must supply rules for building sources it contributes
SENSORS/%.o SENSORS/%.su SENSORS/%.cyclo: ../SENSORS/%.c SENSORS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/Smart Energy Meter with IoT/SmartEnergyMaster/SENSORS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SENSORS

clean-SENSORS:
	-$(RM) ./SENSORS/ADE7953.cyclo ./SENSORS/ADE7953.d ./SENSORS/ADE7953.o ./SENSORS/ADE7953.su ./SENSORS/ESP8266.cyclo ./SENSORS/ESP8266.d ./SENSORS/ESP8266.o ./SENSORS/ESP8266.su ./SENSORS/SSD1306.cyclo ./SENSORS/SSD1306.d ./SENSORS/SSD1306.o ./SENSORS/SSD1306.su

.PHONY: clean-SENSORS

