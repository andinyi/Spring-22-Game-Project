#pragma once
#include "WindowImplementation.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Indev {
	class GlfwWindow : public WindowImplementation 
	{
	public:
		GlfwWindow();
		virtual bool CreateWindow(int x, int y, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~GlfwWindow();	

		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback) override;
	private: 
		struct Callbacks
		{
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} mCallbacks;

		GLFWwindow* mGlfwWindow{ nullptr };
	};
}