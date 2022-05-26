#include "pch.h"
#include "GlfwWindow.h"
#include "IndevUtility.h"
#include "Events.h"

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
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			INDEV_LOG("Glad failed to initialize");

		glfwSetWindowUserPointer(mGlfwWindow, &mCallbacks);

		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvent event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedEvent event{ key };
					userPointer->keyReleasedCallback(event);
				}
			}
		);

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

	void GlfwWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}

	void GlfwWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}
}