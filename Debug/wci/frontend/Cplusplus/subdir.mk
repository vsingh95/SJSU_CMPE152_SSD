################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Cplusplus/CplusplusError.cpp \
../wci/frontend/Cplusplus/CplusplusErrorHandler.cpp \
../wci/frontend/Cplusplus/CplusplusParserTD.cpp \
../wci/frontend/Cplusplus/CplusplusScanner.cpp \
../wci/frontend/Cplusplus/CplusplusToken.cpp 

OBJS += \
./wci/frontend/Cplusplus/CplusplusError.o \
./wci/frontend/Cplusplus/CplusplusErrorHandler.o \
./wci/frontend/Cplusplus/CplusplusParserTD.o \
./wci/frontend/Cplusplus/CplusplusScanner.o \
./wci/frontend/Cplusplus/CplusplusToken.o 

CPP_DEPS += \
./wci/frontend/Cplusplus/CplusplusError.d \
./wci/frontend/Cplusplus/CplusplusErrorHandler.d \
./wci/frontend/Cplusplus/CplusplusParserTD.d \
./wci/frontend/Cplusplus/CplusplusScanner.d \
./wci/frontend/Cplusplus/CplusplusToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Cplusplus/%.o: ../wci/frontend/Cplusplus/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/Users/janettebormann/eclipse-workspace/boost_1_68_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


