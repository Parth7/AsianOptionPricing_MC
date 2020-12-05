cmake_minimum_required(VERSION 3.17)
project(AsianOption_Pricer)

set(CMAKE_CXX_STANDARD 11)

add_executable(AsianOption_Pricer main.cpp PayOff.h PayOff.cpp PathGenerator.h AsianOption.h AsianOption.cpp)