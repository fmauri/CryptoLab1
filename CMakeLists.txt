cmake_minimum_required(VERSION 3.9)
project(L1)

set(CMAKE_CXX_STANDARD 17)

add_executable(L1 main.cpp PseudoRandomGenerator.cpp PseudoRandomGenerator.h Predictor.cpp Predictor.h Calculator.cpp Calculator.h Tester.cpp Tester.h)