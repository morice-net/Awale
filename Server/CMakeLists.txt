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

find_package(Qt5Core REQUIRED)
find_package(Qt5WebSockets REQUIRED)
find_package(Qt5Sql REQUIRED)

add_executable (awaleserver main.cpp awaleserver.cpp gamemaker.cpp accountcreator.cpp messagelistener.cpp sqlitestorage.cpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_link_libraries (awaleserver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} awalelib)

qt5_use_modules(awaleserver Core WebSockets Sql)
