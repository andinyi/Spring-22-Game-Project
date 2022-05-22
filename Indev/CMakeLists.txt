set(HEADER_FILES
	Indev.h
	IndevApp.h
	IndevUtility.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	specificOpenGL/OpenGLSprite.h
	specificOpenGL/OpenGLShader.h
	specificOpenGL/OpenGLRenderer.h
	)

set(SOURCE_FILES
	IndevApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	specificOpenGL/OpenGLSprite.cpp
	specificOpenGL/OpenGLShader.cpp
	specificOpenGL/OpenGLRenderer.cpp
	)

add_library(Indev SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DINDEV_LIB)
add_definitions(-DINDEV_DEBUG)
add_definitions(-DINDEV_OPENGL)

include_directories(../glfw/include)
include_directories(../Indev)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(Indev PRIVATE pch.h)

target_link_libraries(Indev glfw glad stbi)