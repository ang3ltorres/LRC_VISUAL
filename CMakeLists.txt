cmake_minimum_required(VERSION 3.29)
project(LRC_VISUAL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -pedantic -fmax-errors=1)
link_libraries(stdc++exp)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(LRC_VISUAL ${SOURCES})
target_include_directories(LRC_VISUAL PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
