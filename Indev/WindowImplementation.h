#pragma once
#include "pch.h"

namespace Indev
{
	class WindowImplementation {
	public:
		virtual bool CreateWindow(int x, int y, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void CollectEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

	};
}