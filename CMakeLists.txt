cmake_minimum_required(VERSION 3.16)

project(Simple-Pendulum-2D)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(Simple-Pendulum-2D
    src/main.cpp
    src/Components.cpp
)

target_include_directories(Simple-Pendulum-2D
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Simple-Pendulum-2D raylib)
