#include "pch.h"
#include "IndevApp.h"
#include <iostream>
#include "GLFW/glfw3.h"


namespace Indev
{
	void IndevApp::Run()
	{
		INDEV_LOG("Currently running.."); 

		if (!glfwInit()) 
		{
			//Initialization failed
			INDEV_LOG("GLFW failed to initialize");
		}

		GLFWwindow* window;

		window = glfwCreateWindow(800, 600, "game window", NULL, NULL);

		while (true) 
		{
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	void IndevApp::OnUpdate()
	{

	}
}