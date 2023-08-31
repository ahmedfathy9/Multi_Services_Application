cmake_minimum_required(VERSION 3.10)
project(IPC_LIBRARY)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_COMPILER /home/ahmedfathy98/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /home/ahmedfathy98/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu-g++)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost 1.74.0 REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()


add_library(ipc_library STATIC
    receiver.cpp
    sender.cpp
)

target_include_directories(ipc_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# build sender_main.cpp and receiver_main.cpp files
add_executable(sender sender_main.cpp)
target_link_libraries(sender ${Boost_LIBRARIES} ipc_library)

add_executable(receiver receiver_main.cpp)
target_link_libraries(receiver ${Boost_LIBRARIES} ipc_library)

target_link_libraries(sender rt)
target_link_libraries(receiver rt)

