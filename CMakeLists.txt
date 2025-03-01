cmake_minimum_required(VERSION 3.10)
project(Chat VERSION 0.01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(src)

add_library(chat_room_lib src/chat_room.cpp)

add_executable(server src/server.cpp)
target_link_libraries(server PRIVATE chat_room_lib ${Boost_LIBRARIES} pthread)

add_executable(client src/client.cpp)
target_link_libraries(client PRIVATE ${Boost_LIBRARIES} pthread)

option(BUILD_TESTS "Build tests" OFF)

if (BUILD_TESTS)
    add_subdirectory(third_party/gtest)
    add_subdirectory(tests)
endif ()
