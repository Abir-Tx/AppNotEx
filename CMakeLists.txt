# CMake file for AppNotEx project
# By Abir-Tx
# Year: 2021

cmake_minimum_required(VERSION 3.15)

# Project Details
project(AppNotEx VERSION 0.1.0)

# Show Banners/Messages
message("AppNotEx Build System By Abir-Tx")
message("--------------------------------")

# Compiler Flags
set(CMAKE_CXX_FLAGS "-Wall -v -g -Werror -Wextra -Wfatal-errors")

# Place the executable in the bin directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Build
file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include/AppNotEx)
add_executable(appnotex appnotex.cpp ${SOURCES})


message("Done Building AppNotEx")
message("----------------------")




