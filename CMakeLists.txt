cmake_minimum_required(VERSION 3.10)
project(geneticAlgo)

set(CMAKE_CXX_STANDARD 11)

add_executable(geneticAlgo main.cpp src/Individual.cpp src/Individual.hpp src/struct/Set.hpp src/GeneticTransformation.cpp src/GeneticTransformation.hpp src/Generator.cpp src/Generator.hpp Agent.cpp Agent.hpp)