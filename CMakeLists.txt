cmake_minimum_required(VERSION 3.15)

project(WordCounter)

add_subdirectory(cpr)

include_directories(${CPR_INCLUDE_DIRS})

add_executable(WordCounterClient WordCounterClient.cpp)
target_link_libraries(WordCounterClient ${CPR_LIBRARIES})

add_executable(WordCounterServer WordCounterServer.cpp)
target_link_libraries(WordCounterServer -lpistache)

# add_executable(TestWordCounter TestWordCounter.cpp)
# target_link_libraries(TestWordCounter gtest gtest_main -lpthread)
