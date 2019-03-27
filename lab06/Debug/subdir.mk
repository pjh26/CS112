################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Experiment0.cpp \
../Experiment1.cpp \
../Experiment2.cpp \
../main.cpp 

OBJS += \
./Experiment0.o \
./Experiment1.o \
./Experiment2.o \
./main.o 

CPP_DEPS += \
./Experiment0.d \
./Experiment1.d \
./Experiment2.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


