cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ctui LANGUAGES C)
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 23)

set(PROJECT_DEBUG_NAME ${PROJECT_NAME}_debug)


add_subdirectory(cmdio)
add_executable(${PROJECT_DEBUG_NAME} src/main.c src/ctui.c)

target_link_libraries(${PROJECT_DEBUG_NAME} PUBLIC cmdio)
target_include_directories(${PROJECT_DEBUG_NAME} PUBLIC include cmdio)


if (WIN32)
	add_library(${PROJECT_NAME} STATIC src/ctui.c)
else()
	add_library(${PROJECT_NAME} SHARED src/ctui.c)
endif(WIN32)

target_link_libraries(${PROJECT_NAME} PUBLIC cmdio)
target_include_directories(${PROJECT_NAME} PUBLIC include cmdio)
