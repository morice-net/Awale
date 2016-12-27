##############################################################################
##
##  NeO CMake file
##
##############################################################################

cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

# Project definition
##############################################################################

project (Awale)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fext-numeric-literals -L/usr/lib64 -lstdc++")

add_subdirectory(Core)
add_subdirectory(Server)

#qt5_use_modules(Awale Quick Core)
