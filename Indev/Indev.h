#pragma once
#include "IndevApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define INDEV_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}