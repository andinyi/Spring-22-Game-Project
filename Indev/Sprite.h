#pragma once
#include "SpriteImplementation.h"
#include "IndevUtility.h"

namespace Indev
{

	class INDEV_API Sprite
	{
	public:
		Sprite(const std::string& filename);
		int GetWidth() const; 
		int GetHeight() const;

		void Bind();
	private:
		SpriteImplementation* mImplementation; 
	};

}