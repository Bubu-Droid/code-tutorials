cmake_minimum_required (VERSION 3.5)

project(30)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")

add_executable (30 ${source_files})

target_precompile_headers(30 PRIVATE "${source_dir}/pch.h")
