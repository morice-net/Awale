##############################################################################
##
##  NeO CMake file
##
##############################################################################

cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)

# Project definition
##############################################################################

project (Awale)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Quick Core)

qt5_add_resources(RESOURCES qml.qrc)

# set the path to the library folder
link_directories(/usr/local/share/shark/)

add_executable(Awale main.cpp Core/awale.cpp  Core/game.cpp  Core/graphbuilder.cpp  Core/holeevaluator.cpp ${RESOURCES})

qt5_use_modules(Awale Quick Core)

target_link_libraries(Awale shark)
