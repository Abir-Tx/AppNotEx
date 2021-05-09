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
set(CMAKE_CXX_FLAGS "-Wall -v -g -Wextra -Wfatal-errors -lm -lsqlite3")
# Can Be used: -Werror

# Place the executable in the bin directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# Unit Testing using google test
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/f5e592d8ee5ffb1d9af5be7f715ce3576b8bf9c4.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Build
            # Libraries
set(ALIB_LIB "lib/ALib/include/alib")
set(RANG_LIB "lib/ALib/lib/rang")
set(SPDLOG_LIB "lib/spdlog/include")

# priduction build
file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include/AppNotEx/database include/AppNotEx ${ALIB_LIB} ${RANG_LIB} ${SPDLOG_LIB})
add_executable(appnotex appnotex.cpp ${SOURCES})

# testing build
enable_testing()
add_library(testlib STATIC
  include/AppNotEx/database/database.hpp
  ${SOURCES}
)
add_executable(appnotexTest test/appnotexTest.cpp)
target_link_libraries(appnotexTest testlib gtest_main)
# Add CTests
add_test(NAME appnotex_Test COMMAND appnotexTest)

message("Done Building AppNotEx")
message("----------------------")




