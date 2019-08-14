cmake_minimum_required(VERSION 3.15)

project(WordCounter)

add_executable(TestWordCounter TestWordCounter.cpp)
target_link_libraries(TestWordCounter gtest gtest_main -lpthread)