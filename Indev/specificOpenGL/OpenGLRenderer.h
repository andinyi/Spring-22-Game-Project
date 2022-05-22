#pragma once
#include "RendererImplementation.h"

namespace Indev
{
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		virtual void Draw(Indev::Sprite picture, int xPos, int yPos, int zPos, Indev::Shader shader) override;
		virtual void ClearScreen() override;
	};
}
