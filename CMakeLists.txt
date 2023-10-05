cmake_minimum_required(VERSION 3.5.1)

project(data_structures CXX)

find_package(PkgConfig REQUIRED)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    MESSAGE("!! Compiling with debug symbols")
endif()

file(GLOB LIB_SRC src/*.cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")

add_compile_options(-Wall)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${LIB_SRC})

target_link_libraries(${PROJECT_NAME}) 

# Samples
add_subdirectory(samples)
