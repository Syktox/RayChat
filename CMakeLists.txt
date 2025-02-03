cmake_minimum_required(VERSION 3.30)
project(RayChat)

set(CMAKE_CXX_STANDARD 26)

add_library(addDir src/Server/Server.cpp)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE addDir)
