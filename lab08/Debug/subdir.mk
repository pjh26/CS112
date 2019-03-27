################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArrayQueue.cpp \
../ArrayQueueTester.cpp \
../LinkedQueue.cpp \
../LinkedQueueTester.cpp \
../tester.cpp 

OBJS += \
./ArrayQueue.o \
./ArrayQueueTester.o \
./LinkedQueue.o \
./LinkedQueueTester.o \
./tester.o 

CPP_DEPS += \
./ArrayQueue.d \
./ArrayQueueTester.d \
./LinkedQueue.d \
./LinkedQueueTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


