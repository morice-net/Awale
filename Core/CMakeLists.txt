##############################################################################
##
##  NeO CMake file
##
##############################################################################


# Project definition
##############################################################################

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core)

add_library (awalelib awale.cpp  game.cpp  graphbuilder.cpp  holeevaluator.cpp simplecrypt.cpp objectstorage.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link
target_include_directories (awalelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


qt5_use_modules(awalelib Core)
