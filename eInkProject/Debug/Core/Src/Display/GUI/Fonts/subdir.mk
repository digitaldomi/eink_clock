################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Display/GUI/Fonts/font12.c \
../Core/Src/Display/GUI/Fonts/font12CN.c \
../Core/Src/Display/GUI/Fonts/font16.c \
../Core/Src/Display/GUI/Fonts/font20.c \
../Core/Src/Display/GUI/Fonts/font24.c \
../Core/Src/Display/GUI/Fonts/font24CN.c \
../Core/Src/Display/GUI/Fonts/font8.c 

OBJS += \
./Core/Src/Display/GUI/Fonts/font12.o \
./Core/Src/Display/GUI/Fonts/font12CN.o \
./Core/Src/Display/GUI/Fonts/font16.o \
./Core/Src/Display/GUI/Fonts/font20.o \
./Core/Src/Display/GUI/Fonts/font24.o \
./Core/Src/Display/GUI/Fonts/font24CN.o \
./Core/Src/Display/GUI/Fonts/font8.o 

C_DEPS += \
./Core/Src/Display/GUI/Fonts/font12.d \
./Core/Src/Display/GUI/Fonts/font12CN.d \
./Core/Src/Display/GUI/Fonts/font16.d \
./Core/Src/Display/GUI/Fonts/font20.d \
./Core/Src/Display/GUI/Fonts/font24.d \
./Core/Src/Display/GUI/Fonts/font24CN.d \
./Core/Src/Display/GUI/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/GUI/Fonts/font12.o: ../Core/Src/Display/GUI/Fonts/font12.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font12.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font12CN.o: ../Core/Src/Display/GUI/Fonts/font12CN.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font12CN.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font16.o: ../Core/Src/Display/GUI/Fonts/font16.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font16.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font20.o: ../Core/Src/Display/GUI/Fonts/font20.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font20.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font24.o: ../Core/Src/Display/GUI/Fonts/font24.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font24.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font24CN.o: ../Core/Src/Display/GUI/Fonts/font24CN.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font24CN.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/GUI/Fonts/font8.o: ../Core/Src/Display/GUI/Fonts/font8.c Core/Src/Display/GUI/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Core/Src -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/Display -I../Core/Src/Display/Fonts -I../Core/Src/Display/Image -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/Display/GUI/Fonts/font8.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

