cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 17)

include_directories(include) 

set(SOURCES 
    src/main.cpp 
    src/product.cpp 
)

add_executable(main ${SOURCES})
