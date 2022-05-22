#include "pch.h"
#include "IndevApp.h"
#include "GameWindow.h"
#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "stb_image.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

namespace Indev
{
	void IndevApp::Run()
	{
		INDEV_LOG("Currently running.."); 

		Indev::GameWindow::Init();

		GLFWwindow* window;

		Indev::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		Renderer::Init();

		Indev::Shader shader{ "../Indev/Assets/Shaders/defaultVertex.glsl", "../Indev/Assets/Shaders/defaultFragment.glsl"};
		shader.SetUniform2Ints("windowSize", 800, 600);
		shader.SetUniform3Ints("spriteCoord", 0, 0, 1.0);

		//--------------------TEXTURES------------------------------------------------------------------------------------///
		Indev::Sprite star{ "../Indev/Assets/Images/image.png" };

		int xPos{ -star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) 
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, xPos, 20, 1); 

			xPos = (xPos + 5); // % (Indev::GameWindow::GetWindow()->GetWidth() + star.GetWidth()) - star.GetWidth();

			std::this_thread::sleep_until(mNextFrameTime);

			Indev::GameWindow::GetWindow()->SwapBuffers();
			Indev::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void IndevApp::OnUpdate()
	{

	}
}