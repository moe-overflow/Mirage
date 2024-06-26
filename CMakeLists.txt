cmake_minimum_required(VERSION 3.25)

project(
    mirage
    VERSION 0.0.1
    DESCRIPTION "A simple 2d game/physics engine"
    LANGUAGES C CXX

)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(WIN32)
    add_compile_definitions(MIRAGE_PLATFORM_WINDOWS)
endif()

add_subdirectory(src/mirage)
add_subdirectory(src/sandbox)
add_subdirectory(vendor)
add_subdirectory(test)


include(${CMAKE_SOURCE_DIR}/cmake/dependency_manager.cmake)
load_dependencies()
