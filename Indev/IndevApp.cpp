#include "pch.h"
#include "IndevApp.h"
#include "GameWindow.h"
#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "stb_image.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

namespace Indev
{

	IndevApp::IndevApp()
	{
		INDEV_LOG("Currently running..");

		Indev::GameWindow::Init();

		GLFWwindow* window;

		Indev::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		Renderer::Init();
	}

	void IndevApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) 
		{
			Renderer::ClearScreen();

			OnUpdate();

			 // % (Indev::GameWindow::GetWindow()->GetWidth() + star.GetWidth()) - star.GetWidth();

			std::this_thread::sleep_until(mNextFrameTime);

			Indev::GameWindow::GetWindow()->SwapBuffers();
			Indev::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void IndevApp::OnUpdate()
	{

	}
	void IndevApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}
	void IndevApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}
}