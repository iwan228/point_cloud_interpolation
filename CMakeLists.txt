cmake_minimum_required(VERSION 3.29)
project(point_cloud_interpolation)

set(CMAKE_CXX_STANDARD 26)

add_executable(point_cloud_interpolation src/main.cpp
        include/idw.h
        include/grid.h
        include/point.h
        include/utils.h
        src/idw.cpp
        src/grid.cpp
        src/utils.cpp)
