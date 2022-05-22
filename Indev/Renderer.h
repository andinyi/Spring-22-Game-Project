#pragma once
#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "IndevUtility.h"

namespace Indev
{
	class INDEV_API Renderer
	{
	public:
		static void Init();
		static void Draw(Indev::Sprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();

	private: 
		inline static Renderer* mInstance{ nullptr };
		RendererImplementation* mImplementation{ nullptr };
		Renderer();
		Indev::Shader mShader;
	};
}

