# General configs
cmake_minimum_required(VERSION 3.24)
project(StarField)
set(CMAKE_CXX_STANDARD 17)

# Variable to hold a list of all source files for this project
set(SOURCE_FILES main.cpp Star.cpp Star.h)

# Add the raylib library to this project
find_package(raylib 4.2.0 REQUIRED)

# Create the executable target
add_executable(StarField ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
