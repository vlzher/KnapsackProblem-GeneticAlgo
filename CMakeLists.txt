cmake_minimum_required(VERSION 3.23)
project(miniproject)

set(CMAKE_CXX_STANDARD 14)

add_executable(miniproject main.cpp CKnapsackProblem.cpp CKnapsackProblem.h CGeneticAlgorithm.cpp CGeneticAlgorithm.h Individual.cpp Individual.h)
