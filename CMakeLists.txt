# CMake file for AppNotEx project
# By Abir-Tx
# Year: 2021

cmake_minimum_required(VERSION 3.15)

# Project Details
project(AppNotEx VERSION 1.0.0)

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
if(LSB_RELEASE_ID_SHORT STREQUAL "Ubuntu")
  message("You are on Ubuntu !")
  message("")
  set(CMAKE_CXX_FLAGS "-Wall -v -g -Wextra -Wfatal-errors -lm -pthread")
else()
  set(CMAKE_CXX_FLAGS "-lm -lpthread")
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

# Build Configs
            # Sources and Headers of AppNotEx
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/AppNotEx/*.hpp")
            # Libraries
set(ALIB_LIB "lib/ALib/include/alib")
set(RANG_LIB "lib/ALib/lib/rang")
set(SPDLOG_LIB "lib/spdlog/include")
set(JSONCPP_LIB "lib/jsoncpp/include/json")
                          # My Own AppNotexLib
add_library(appnotexd STATIC
  ${HEADERS}
  ${SOURCES}
)

# Production build
# -------------------------------------appnotex----------------------------------------

# Add the jsoncpp lib project
# add_subdirectory(lib/jsoncpp)
# 
# Search for sqlite3 library using the built in SQLite3 package in cmake
find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(include/AppNotEx/database include/AppNotEx/notex include/AppNotEx ${ALIB_LIB} ${RANG_LIB} ${SPDLOG_LIB} ${JSONCPP_LIB})
  add_executable(appnotex appnotex.cpp ${SOURCES})
  include_directories(${SQLITE3_INCLUDE_DIRS})
  target_link_libraries (appnotex ${SQLITE3_LIBRARIES} sqlite3 jsoncpp)
endif (SQLITE3_FOUND)

# ---------------------------------------notex------------------------------------------
add_executable(notex notex.cpp ${SOURCES})
target_link_libraries(notex sqlite3)


# Install
install(TARGETS appnotex notex DESTINATION bin)

# Testing build
enable_testing()
add_executable(appnotexTest test/appnotexTest.cpp)
target_link_libraries(appnotexTest appnotexd gtest_main sqlite3)
# Add CMAKE CTests
add_test(NAME appnotex_Test COMMAND appnotexTest)

# Build done message
message("Done Building AppNotEx")
message("----------------------")
