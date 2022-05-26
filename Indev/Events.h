#pragma once

#include "IndevUtility.h"

namespace Indev
{
	class INDEV_API KeyPressedEvent
	{
	public: 
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class INDEV_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}


