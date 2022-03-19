#pragma once
#include "pch.h"

#ifdef INDEV_LIB
	#define INDEV_API __declspec(dllexport)
#else
	#define INDEV_API __declspec(dllimport)
#endif 

#ifdef INDEV_DEBUG
	#define INDEV_LOG(x) std::cout << x << std::endl;
#else
	#define INDEV_LOG(x)
#endif // 
