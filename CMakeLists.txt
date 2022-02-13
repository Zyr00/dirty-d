cmake_minimum_required(VERSION 3.12...3.22 FATAL_ERROR)

set(PROJ "dirty-d")
set(SERVER "src/server")
set(CLIENT "src/client")

project(${PROJ} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(${SERVER})
add_subdirectory(${CLIENT})
