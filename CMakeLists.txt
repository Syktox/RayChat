cmake_minimum_required(VERSION 3.14)
project(RayChat)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(addDir src/Server/Server.cpp)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE addDir)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${json_SOURCE_DIR}/include)