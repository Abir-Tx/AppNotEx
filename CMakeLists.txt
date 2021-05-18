# CMake file for AppNotEx project
# By Abir-Tx
# Year: 2021

cmake_minimum_required(VERSION 3.15)

# Project Details
project(AppNotEx VERSION 0.1.0)

# Show Banners/Messages
message("AppNotEx Build System By Abir-Tx")
message("--------------------------------")

# Detect OS (Distro)
find_program(LSB_RELEASE_EXEC lsb_release)
execute_process(COMMAND ${LSB_RELEASE_EXEC} -is
    OUTPUT_VARIABLE LSB_RELEASE_ID_SHORT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Compiler Flags
if($LSB_RELEASE_ID_SHORT EQUAL "Ubuntu")
  message("You are on Ubuntu !")
  set(CMAKE_CXX_FLAGS "-Wall -v -g -Wextra -Wfatal-errors -lm -L/usr/lib/x86_64-Linux-gnu/ -lsqlite3")
else()
  set(CMAKE_CXX_FLAGS "-Wall -v -g -Wextra -Wfatal-errors -lm -L/usr/lib -lsqlite3")
endif()


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
            # Sources and Headers of AppNotEx
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/AppNotEx/*.hpp")
            # Libraries
set(ALIB_LIB "lib/ALib/include/alib")
set(RANG_LIB "lib/ALib/lib/rang")
set(SPDLOG_LIB "lib/spdlog/include")
                          # My Own AppNotexLib
add_library(appnotexd STATIC
  ${HEADERS}
  ${SOURCES}
)

# Production build
# -------------------------------------appnotex----------------------------------------
include_directories(include/AppNotEx/database include/AppNotEx/notex include/AppNotEx ${ALIB_LIB} ${RANG_LIB} ${SPDLOG_LIB})
add_executable(appnotex appnotex.cpp ${SOURCES})
# ---------------------------------------notex------------------------------------------
add_executable(notex notex.cpp ${SOURCES})
# Install
install(TARGETS appnotex DESTINATION bin)

# Testing build
enable_testing()
add_executable(appnotexTest test/appnotexTest.cpp)
target_link_libraries(appnotexTest appnotexd gtest_main)
# Add CMAKE CTests
add_test(NAME appnotex_Test COMMAND appnotexTest)

# Build done message
message("Done Building AppNotEx")
message("----------------------")
