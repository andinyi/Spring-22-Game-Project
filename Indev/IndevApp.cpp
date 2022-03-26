#include "pch.h"
#include "IndevApp.h"
#include "GLFW/glfw3.h"
#include "GameWindow.h"

namespace Indev
{
	void IndevApp::Run()
	{
		INDEV_LOG("Currently running.."); 

		Indev::GameWindow::Init();

		GLFWwindow* window;

		Indev::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		while (true) 
		{
			OnUpdate();
			Indev::GameWindow::GetWindow()->SwapBuffers();
			Indev::GameWindow::GetWindow()->CollectEvents();
		}
	}
	void IndevApp::OnUpdate()
	{

	}
}