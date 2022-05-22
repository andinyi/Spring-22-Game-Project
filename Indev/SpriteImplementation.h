#pragma once

namespace Indev
{
	class SpriteImplementation
	{
	public: 
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void Bind() = 0;
		virtual bool IsBound() const = 0;

	};
}