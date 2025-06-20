cmake_minimum_required(VERSION 3.29)
project(point_cloud_interpolation)

set(CMAKE_CXX_STANDARD 26)

add_executable(point_cloud_interpolation
        src/main.cpp
        src/idw.cpp
        src/grid.cpp
        src/utils.cpp
        src/point.cpp
)

target_include_directories(point_cloud_interpolation
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
