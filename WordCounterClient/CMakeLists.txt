cmake_minimum_required(VERSION 3.15)

set(this WordCounter-Client)

project(${this})

include_directories(
    ${CPR_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${this} src/WordCounterClient.cpp)
target_link_libraries(${this} ${CPR_LIBRARIES})