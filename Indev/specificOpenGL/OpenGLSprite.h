#pragma once
#include "SpriteImplementation.h"

namespace Indev
{
	class OpenGLSprite : public SpriteImplementation
	{
	public:
		OpenGLSprite(const std::string& filename);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;
	
	private:
		unsigned int mVAO;
		unsigned int mVBO;
		unsigned int mEBO;
		unsigned int mTex;
		int mWidth{ 0 };
		int mHeight{ 0 };

	};
}

