cmake_minimum_required(VERSION 3.20)

project(Geometry)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(Geometry ${SOURCES})
