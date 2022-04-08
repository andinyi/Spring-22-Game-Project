#pragma once
#include "pch.h"

#ifdef INDEV_WINDOWS
	#ifdef INDEV_LIB
		#define INDEV_API __declspec(dllexport)
	#else
		#define INDEV_API __declspec(dllimport)
	#endif
#else
	#define INDEV_API
#endif

#ifdef INDEV_DEBUG
	#define INDEV_LOG(x) std::cout << x << std::endl;
#else
	#define INDEV_LOG(x)
#endif // 
