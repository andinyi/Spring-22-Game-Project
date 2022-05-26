#pragma once
#include "IndevUtility.h"
#include "pch.h"
#include "Events.h"
#include "KeyCodes.h"

#define INDEV_FRAMERATE 60

namespace Indev
{
	class INDEV_API IndevApp
	{
	public: 
		IndevApp();
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);
	
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / INDEV_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}


