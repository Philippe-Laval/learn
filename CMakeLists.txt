cmake_minimum_required(VERSION 3.22)
project(learn)

set(CMAKE_CXX_STANDARD 20)

add_executable(learn main.cpp Lib.cpp Lib.h Literals.cpp Literals.h OperatorPrecedence.cpp OperatorPrecedence.h FloatingPointArithmetic.cpp FloatingPointArithmetic.h BitOperators.h BitOperators.cpp BitManipulation.cpp BitManipulation.h BitFields.cpp BitFields.h Arrays.cpp Arrays.h Iterators.cpp Iterators.h)
