################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Games/BreakOut/Ball.cpp \
../src/Games/BreakOut/BreakOut.cpp \
../src/Games/BreakOut/Excluder.cpp \
../src/Games/BreakOut/Paddle.cpp 

OBJS += \
./src/Games/BreakOut/Ball.o \
./src/Games/BreakOut/BreakOut.o \
./src/Games/BreakOut/Excluder.o \
./src/Games/BreakOut/Paddle.o 

CPP_DEPS += \
./src/Games/BreakOut/Ball.d \
./src/Games/BreakOut/BreakOut.d \
./src/Games/BreakOut/Excluder.d \
./src/Games/BreakOut/Paddle.d 


# Each subdirectory must supply rules for building sources it contributes
src/Games/BreakOut/%.o: ../src/Games/BreakOut/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++14 -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Graphics" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Scenes -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Utils -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Shapes -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/App" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/input -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games/BreakOut -O0 -g3 -Wall -c -fmessage-length=0 -static-libgcc -static-libstdc++ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


