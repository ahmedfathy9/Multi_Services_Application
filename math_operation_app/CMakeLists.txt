cmake_minimum_required(VERSION 3.10)
project(MathOpApp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_COMPILER /home/ahmedfathy98/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /home/ahmedfathy98/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-g++)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost 1.74.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()
include_directories(${Boost_INCLUDE_DIRS})



add_executable(MathOpApp main.cpp math_operation.cpp)

target_link_libraries(MathOpApp ${Boost_LIBRARIES})

