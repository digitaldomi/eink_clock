################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Display/eInk_config/DEV_Config.c \
../Core/Src/Display/eInk_config/EPD_2in13_V2.c \
../Core/Src/Display/eInk_config/EPD_2in13_V2_test.c 

OBJS += \
./Core/Src/Display/eInk_config/DEV_Config.o \
./Core/Src/Display/eInk_config/EPD_2in13_V2.o \
./Core/Src/Display/eInk_config/EPD_2in13_V2_test.o 

C_DEPS += \
./Core/Src/Display/eInk_config/DEV_Config.d \
./Core/Src/Display/eInk_config/EPD_2in13_V2.d \
./Core/Src/Display/eInk_config/EPD_2in13_V2_test.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/eInk_config/DEV_Config.o: ../Core/Src/Display/eInk_config/DEV_Config.c Core/Src/Display/eInk_config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/eInk_config/DEV_Config.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/eInk_config/EPD_2in13_V2.o: ../Core/Src/Display/eInk_config/EPD_2in13_V2.c Core/Src/Display/eInk_config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/eInk_config/EPD_2in13_V2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/eInk_config/EPD_2in13_V2_test.o: ../Core/Src/Display/eInk_config/EPD_2in13_V2_test.c Core/Src/Display/eInk_config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/eInk_config/EPD_2in13_V2_test.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

