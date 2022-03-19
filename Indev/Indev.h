#pragma once
#include "IndevApp.h"

#define INDEV_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}