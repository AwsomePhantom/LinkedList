cmake_minimum_required(VERSION 3.5)

project(DSAILAB-Assignment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DSAILAB-Assignment main.cpp snode.h dnode.h circularlist.h circularlist.cpp doublelist.h doublelist.cpp)

install(TARGETS DSAILAB-Assignment
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
