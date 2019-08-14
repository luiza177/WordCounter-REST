cmake_minimum_required(VERSION 3.15)

project(server)

# add_executable(fuckyou hello.cpp)
add_executable(fuckyou bottle.cpp)
target_link_libraries(fuckyou -lpistache)