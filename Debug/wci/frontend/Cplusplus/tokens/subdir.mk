################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Cplusplus/tokens/CplusplusErrorToken.cpp \
../wci/frontend/Cplusplus/tokens/CplusplusNumberToken.cpp \
../wci/frontend/Cplusplus/tokens/CplusplusSpecialSymbolToken.cpp \
../wci/frontend/Cplusplus/tokens/CplusplusStringToken.cpp \
../wci/frontend/Cplusplus/tokens/CplusplusWordToken.cpp 

OBJS += \
./wci/frontend/Cplusplus/tokens/CplusplusErrorToken.o \
./wci/frontend/Cplusplus/tokens/CplusplusNumberToken.o \
./wci/frontend/Cplusplus/tokens/CplusplusSpecialSymbolToken.o \
./wci/frontend/Cplusplus/tokens/CplusplusStringToken.o \
./wci/frontend/Cplusplus/tokens/CplusplusWordToken.o 

CPP_DEPS += \
./wci/frontend/Cplusplus/tokens/CplusplusErrorToken.d \
./wci/frontend/Cplusplus/tokens/CplusplusNumberToken.d \
./wci/frontend/Cplusplus/tokens/CplusplusSpecialSymbolToken.d \
./wci/frontend/Cplusplus/tokens/CplusplusStringToken.d \
./wci/frontend/Cplusplus/tokens/CplusplusWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Cplusplus/tokens/%.o: ../wci/frontend/Cplusplus/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/Users/hmmm/Downloads/boost_1_68_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


