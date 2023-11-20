################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Shapes/AARectangle.cpp \
../src/Shapes/Circle.cpp \
../src/Shapes/Line.cpp \
../src/Shapes/Shape.cpp \
../src/Shapes/Triangle.cpp 

OBJS += \
./src/Shapes/AARectangle.o \
./src/Shapes/Circle.o \
./src/Shapes/Line.o \
./src/Shapes/Shape.o \
./src/Shapes/Triangle.o 

CPP_DEPS += \
./src/Shapes/AARectangle.d \
./src/Shapes/Circle.d \
./src/Shapes/Line.d \
./src/Shapes/Shape.d \
./src/Shapes/Triangle.d 


# Each subdirectory must supply rules for building sources it contributes
src/Shapes/%.o: ../src/Shapes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++14 -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Graphics" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Scenes -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Utils -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Shapes -I"/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/App" -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/input -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games -I/home/sherif/Desktop/stuff/eclipse_workspace/ArcadeApp/src/Games/BreakOut -O0 -g3 -Wall -c -fmessage-length=0 -static-libgcc -static-libstdc++ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


