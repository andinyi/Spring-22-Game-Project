set(HEADER_FILES
	Indev.h
	IndevApp.h
	IndevUtility.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	)

set(SOURCE_FILES
	IndevApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	)

add_library(Indev SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DINDEV_LIB)
add_definitions(-DINDEV_DEBUG)

include_directories(../glfw/include)
include_directories(../Indev)

target_precompile_headers(Indev PRIVATE pch.h)

target_link_libraries(Indev glfw)