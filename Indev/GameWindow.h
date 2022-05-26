#pragma once
#include "WindowImplementation.h"
#include "IndevUtility.h"
#include "Events.h"

namespace Indev 
{
	class INDEV_API GameWindow
	{
		public:
			static void Init();
			static GameWindow* GetWindow();

			bool CreateWindow(int x, int y, const std::string& windowName);
			void SwapBuffers();
			void CollectEvents();
			int GetWidth() const;
			int GetHeight() const;

			void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
			void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

		private:
			inline static GameWindow* instance { nullptr };

			GameWindow();

			WindowImplementation* newWindow{ nullptr };
	};
}
