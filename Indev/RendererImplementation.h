#pragma once
#include "Shader.h"
#include "Sprite.h"

namespace Indev
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Indev::Sprite picture, int xPos, int yPos, int zPos, Indev::Shader shader) = 0;
		virtual void ClearScreen() = 0;
	private:

	};
}
