################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Display/GUI/GUI_Paint.c 

OBJS += \
./Core/Src/Display/GUI/GUI_Paint.o 

C_DEPS += \
./Core/Src/Display/GUI/GUI_Paint.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/GUI/GUI_Paint.o: ../Core/Src/Display/GUI/GUI_Paint.c Core/Src/Display/GUI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/GUI_Paint.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

