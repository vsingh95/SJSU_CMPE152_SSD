################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Cpp/CppError.cpp \
../wci/frontend/Cpp/CppErrorHandler.cpp \
../wci/frontend/Cpp/CppParserTD.cpp \
../wci/frontend/Cpp/CppScanner.cpp \
../wci/frontend/Cpp/CppToken.cpp 

OBJS += \
./wci/frontend/Cpp/CppError.o \
./wci/frontend/Cpp/CppErrorHandler.o \
./wci/frontend/Cpp/CppParserTD.o \
./wci/frontend/Cpp/CppScanner.o \
./wci/frontend/Cpp/CppToken.o 

CPP_DEPS += \
./wci/frontend/Cpp/CppError.d \
./wci/frontend/Cpp/CppErrorHandler.d \
./wci/frontend/Cpp/CppParserTD.d \
./wci/frontend/Cpp/CppScanner.d \
./wci/frontend/Cpp/CppToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Cpp/%.o: ../wci/frontend/Cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/Users/hmmm/Downloads/boost_1_68_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


