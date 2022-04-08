#pragma once
#include "WindowImplementation.h"
#include "IndevUtility.h"

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

		private:
			inline static GameWindow* instance { nullptr };

			GameWindow();

			WindowImplementation* newWindow{ nullptr };
	};
}
