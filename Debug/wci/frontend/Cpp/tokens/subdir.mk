################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Cpp/tokens/CppErrorToken.cpp \
../wci/frontend/Cpp/tokens/CppNumberToken.cpp \
../wci/frontend/Cpp/tokens/CppSpecialSymbolToken.cpp \
../wci/frontend/Cpp/tokens/CppStringToken.cpp \
../wci/frontend/Cpp/tokens/CppWordToken.cpp 

OBJS += \
./wci/frontend/Cpp/tokens/CppErrorToken.o \
./wci/frontend/Cpp/tokens/CppNumberToken.o \
./wci/frontend/Cpp/tokens/CppSpecialSymbolToken.o \
./wci/frontend/Cpp/tokens/CppStringToken.o \
./wci/frontend/Cpp/tokens/CppWordToken.o 

CPP_DEPS += \
./wci/frontend/Cpp/tokens/CppErrorToken.d \
./wci/frontend/Cpp/tokens/CppNumberToken.d \
./wci/frontend/Cpp/tokens/CppSpecialSymbolToken.d \
./wci/frontend/Cpp/tokens/CppStringToken.d \
./wci/frontend/Cpp/tokens/CppWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Cpp/tokens/%.o: ../wci/frontend/Cpp/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/Users/hmmm/Downloads/boost_1_68_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


