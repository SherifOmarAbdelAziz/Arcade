################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Utils/FileCommandLoader.cpp \
../src/Utils/Utils.cpp \
../src/Utils/Vec2D.cpp 

OBJS += \
./src/Utils/FileCommandLoader.o \
./src/Utils/Utils.o \
./src/Utils/Vec2D.o 

CPP_DEPS += \
./src/Utils/FileCommandLoader.d \
./src/Utils/Utils.d \
./src/Utils/Vec2D.d 


# Each subdirectory must supply rules for building sources it contributes
src/Utils/%.o: ../src/Utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++14 -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Graphics" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Scenes -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Utils -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Shapes -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/App" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/input -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games/BreakOut -O0 -g3 -Wall -c -fmessage-length=0 -static-libgcc -static-libstdc++ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


