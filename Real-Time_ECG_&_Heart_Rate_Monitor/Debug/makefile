################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sensors/subdir.mk
-include FreeRtos/Source/portable/MemMang/subdir.mk
-include FreeRtos/Source/portable/GCC/ARM_CM4F/subdir.mk
-include FreeRtos/Source/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Heart Rate Monitor
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Heart\ Rate\ Monitor.elf \

MAP_FILES += \
Heart\ Rate\ Monitor.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Heart\ Rate\ Monitor.list \

OBJCOPY_HEX += \
Heart\ Rate\ Monitor.hex \

OBJCOPY_BIN += \
Heart\ Rate\ Monitor.bin \


# All Target
all: main-build

# Main-build Target
main-build: Heart\ Rate\ Monitor.elf secondary-outputs

# Tool invocations
Heart\ Rate\ Monitor.elf Heart\ Rate\ Monitor.map: $(OBJS) $(USER_OBJS) E:\Projecrs\New\ folder\STM32F401RCTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Heart Rate Monitor.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\Projecrs\New folder\STM32F401RCTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Heart Rate Monitor.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Heart\ Rate\ Monitor.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Heart Rate Monitor.list"
	@echo 'Finished building: $@'
	@echo ' '

Heart\ Rate\ Monitor.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Heart Rate Monitor.hex"
	@echo 'Finished building: $@'
	@echo ' '

Heart\ Rate\ Monitor.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Heart Rate Monitor.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Heart\ Rate\ Monitor.bin Heart\ Rate\ Monitor.elf Heart\ Rate\ Monitor.hex Heart\ Rate\ Monitor.list Heart\ Rate\ Monitor.map Heart\\ Rate\\ Monitor.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
