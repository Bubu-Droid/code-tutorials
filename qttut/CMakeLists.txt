cmake_minimum_required (VERSION 3.25)

project(qttut LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -std=c++23")
set(source_dir "${PROJECT_SOURCE_DIR}/src")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable (qttut
  "${source_dir}/main.cpp"
)

target_link_libraries(qttut PRIVATE Qt6::Widgets)
