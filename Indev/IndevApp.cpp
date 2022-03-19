#include "pch.h"
#include "IndevApp.h"
#include <iostream>


namespace Indev
{
	void IndevApp::Run()
	{
		INDEV_LOG("Currently running.."); 
		while (true) 
		{
			OnUpdate();
		}
	}
	void IndevApp::OnUpdate()
	{

	}
}