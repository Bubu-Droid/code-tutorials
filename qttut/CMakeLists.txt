cmake_minimum_required (VERSION 3.25)

project(qttut VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -std=c++23")
set(source_dir "${PROJECT_SOURCE_DIR}/src")

# find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable (qttut
  "${source_dir}/main.cpp"
)

target_link_libraries(qttut PRIVATE Qt6::Widgets)

set_target_properties(qttut PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
