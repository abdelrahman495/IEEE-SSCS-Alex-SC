################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SYSTICK/SYSTICK_Program.c 

OBJS += \
./MCAL/SYSTICK/SYSTICK_Program.o 

C_DEPS += \
./MCAL/SYSTICK/SYSTICK_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SYSTICK/%.o MCAL/SYSTICK/%.su MCAL/SYSTICK/%.cyclo: ../MCAL/SYSTICK/%.c MCAL/SYSTICK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-SYSTICK

clean-MCAL-2f-SYSTICK:
	-$(RM) ./MCAL/SYSTICK/SYSTICK_Program.cyclo ./MCAL/SYSTICK/SYSTICK_Program.d ./MCAL/SYSTICK/SYSTICK_Program.o ./MCAL/SYSTICK/SYSTICK_Program.su

.PHONY: clean-MCAL-2f-SYSTICK

