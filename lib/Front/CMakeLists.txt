cmake_minimum_required(VERSION 3.20)
project(OverflowProject)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX STANDARD 14)

set(SOURCE_DIR src)
set(HEADERS_DIR include)

set(ALIAS "[Frontend]")

add_compile_options(-Wall -Wextra -pedantic)

if (CMAKE_BUILD_TYPE=Release)
    add_compile_options(-O3)
elseif(CMAKE_BUILD_TYPE=Debug)
    add_compile_options(-g)
endif()

if (COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

if (WPADDED)
    add_compile_options(-Wpadded)
endif()

add_library(Front ${SOURCE_DIR}/server.cpp ${SOURCE_DIR}/settings.cpp)
target_include_directories(Front PUBLIC ${HEADERS_DIR})

target_link_libraries(Front)

if (CMAKE_BUILD_TYPE STREQUAL Release)
    message("${ALIAS} Использую WebToolkit [Release].")
    target_link_libraries(Front wt wthttp)
elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
    message("${ALIAS} Использую WebToolkit [Debug].")
    target_link_libraries(Front wtd wthttpd)
endif()