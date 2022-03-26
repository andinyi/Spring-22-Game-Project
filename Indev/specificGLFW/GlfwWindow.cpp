#include "pch.h"
#include "GlfwWindow.h"
#include "IndevUtility.h"

namespace Indev 
{
	GlfwWindow::GlfwWindow() 
	{
		if (!glfwInit()) 
		{
			INDEV_LOG("GLFW failed to initialize");
		}
	}

	bool GlfwWindow::CreateWindow(int x, int y, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(x, y, windowName.c_str(), NULL, NULL);

		if (mGlfwWindow == nullptr) {
			INDEV_LOG("Window Creation failed.");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);

		return true;
	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWindow::CollectEvents() 
	{
		glfwPollEvents();
	}
	
	int GlfwWindow::GetWidth() const
	{
		int x, y;
		glfwGetWindowSize(mGlfwWindow, &x, &y);

		return x;
	}

	int GlfwWindow::GetHeight() const
	{
		int x, y;
		glfwGetWindowSize(mGlfwWindow, &x, &y);

		return y;
	}
	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow != nullptr)
		{
			glfwTerminate();
		}
	}
}