cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Project name
project(imc_cpp)

# Where to find included source files
include_directories("${PROJECT_SOURCE_DIR}")

# List sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")

# Create a (static by default) library using all of IMC sources / headers
add_library(imc ${IMC_SOURCES})

# Create udp library
add_library(udp UDP/DatagramSocket.cpp)

# imc_101 executable
add_executable(imc_101 imc101.cpp)
target_link_libraries(imc_101 imc udp)
