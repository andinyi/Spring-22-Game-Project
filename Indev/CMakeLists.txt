add_library(Indev SHARED Indev.h IndevApp.h IndevUtility.h IndevApp.cpp)

add_definitions(-DINDEV_LIB)
add_definitions(-DINDEV_DEBUG)

target_precompile_headers(Indev PRIVATE pch.h)