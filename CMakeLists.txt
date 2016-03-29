##############################################################################
##
##  NeO CMake file
##
##############################################################################

cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

# Project definition
##############################################################################

project (Awale)

add_subdirectory(Core)
add_subdirectory(Server)


#qt5_use_modules(Awale Quick Core)
