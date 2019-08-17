cmake_minimum_required(VERSION 3.15)

set(this WordCounter)

project(${this})

set(WORDCOUNTER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

include_directories(
    ${WORDCOUNTER_INCLUDE_DIR}
    ${GTEST_INCLUDE_DIRS}
)

# do test integration with cmake
add_executable(TestWordCounter test/TestWordCounter.cpp)
target_link_libraries(TestWordCounter gtest gtest_main)