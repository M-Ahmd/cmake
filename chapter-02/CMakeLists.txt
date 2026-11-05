cmake_minimum_required(VERSION 3.15)
project(ProjectLayout LANGUAGES CXX)

add_library(greeting src/greeting.cpp)
target_include_directories(greeting PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(greeting-app src/main.cpp)
target_link_libraries(greeting-app PRIVATE greeting)
