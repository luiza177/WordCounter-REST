cmake_minimum_required(VERSION 3.15)

set(this WordCounter-Server)

project(${this})

include_directories(
    ${WORDCOUNTER_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${this} src/WordCounterServer.cpp)
target_link_libraries(${this} -lpistache)