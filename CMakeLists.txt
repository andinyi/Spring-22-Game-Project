cmake_minimum_required(VERSION 3.16)

project(Spring22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DINDEV_WINDOWS)
elseif(APPLE)
	add_definitions(-DINDEV_MACOS)
elseif(UNIX)
	add_definitions(-DINDEV_LINUX)
endif()

add_subdirectory(Spring22)
add_subdirectory(Indev)
add_subdirectory(glfw)
