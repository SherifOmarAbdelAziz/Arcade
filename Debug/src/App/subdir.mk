################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/App/App.cpp 

OBJS += \
./src/App/App.o 

CPP_DEPS += \
./src/App/App.d 


# Each subdirectory must supply rules for building sources it contributes
src/App/%.o: ../src/App/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++14 -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Graphics" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Scenes -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Utils -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Shapes -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/App" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/input -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games/BreakOut -O0 -g3 -Wall -c -fmessage-length=0 -static-libgcc -static-libstdc++ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


