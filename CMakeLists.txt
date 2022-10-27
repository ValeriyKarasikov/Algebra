#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.19.7)

project(CT_FEM_3D VERSION 3.19.7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -ggdb)
#add_compile_options(-Wall -Ofast)

#-------------------------------------------------------------------------------

add_executable(launcher main.cpp)

#-------------------------------------------------------------------------------
