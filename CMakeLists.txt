cmake_minimum_required(VERSION 2.8)

project(neural-threads)

add_executable(neural-threads layer.cpp network.cpp neuron.cpp main.cpp)

install(TARGETS neural-threads RUNTIME DESTINATION bin)

add_executable(neural-threads-tests neuron.cpp layer.cpp tests/tests_simple.cpp)
target_link_libraries(neural-threads-tests gtest)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -Wall -ftest-coverage -fprofile-arcs")
add_subdirectory(tests)