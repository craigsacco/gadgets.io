cmake_minimum_required(VERSION 3.24)

project(InterfaceIO LANGUAGES CXX)

# set C++ dialect to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enable VS project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# add third-party libraries to scope
add_subdirectory(../3rdParty 3rdParty)

# add subdirectories to project scope
add_subdirectory(Core)
add_subdirectory(Devices)
