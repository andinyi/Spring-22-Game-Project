#pragma once
#include "IndevUtility.h"
#include "pch.h"

#define INDEV_FRAMERATE 60

namespace Indev
{
	class INDEV_API IndevApp
	{
	public: 
		void Run();
		virtual void OnUpdate();
	
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / INDEV_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}


