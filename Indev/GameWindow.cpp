#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW/GlfwWindow.h"


void Indev::GameWindow::Init()
{
	if (instance == nullptr) {
		instance = new GameWindow;
	}
}

Indev::GameWindow* Indev::GameWindow::GetWindow()
{
	assert(instance);
	return instance;
}

bool Indev::GameWindow::CreateWindow(int x, int y, const std::string& windowName)
{
	return newWindow->CreateWindow(800, 512, "Spring 2022");
}

void Indev::GameWindow::SwapBuffers()
{
	newWindow->SwapBuffers();
}

void Indev::GameWindow::CollectEvents()
{
	newWindow->CollectEvents();
}

int Indev::GameWindow::GetWidth() const
{
	return newWindow->GetWidth();
}

int Indev::GameWindow::GetHeight() const
{
	return newWindow->GetHeight();
}

void Indev::GameWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
{
	newWindow->SetKeyPressedCallback(keyPressedCallback);
}

void Indev::GameWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
{
	newWindow->SetKeyReleasedCallback(keyReleasedCallback);
}

Indev::GameWindow::GameWindow() 
{
#ifdef INDEV_WINDOWS
	newWindow = new GlfwWindow;
#elif defined INDEV_MACOS
	newWindow = new GlfwWindow;
#elif defined INDEV_LINUS
	newWindow = new GlfwWindow;
#else
	#Unsupported_platform
#endif
}
