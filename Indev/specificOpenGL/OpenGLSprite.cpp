#include "pch.h"
#include "IndevUtility.h"
#include "glad/glad.h"
#include "OpenGLSprite.h"
#include "stb_image.h"

namespace Indev
{
	OpenGLSprite::OpenGLSprite(const std::string& fileName)
	{
		stbi_set_flip_vertically_on_load(true);

		int numChannels;
		unsigned char* data = stbi_load(fileName.c_str(), &mWidth, &mHeight, &numChannels, 0);

		if (data == NULL) {
			INDEV_LOG("ERROR: texture did not load");
		}

		float vertices[] =
		{
					  0.0f,            0.0f, 0.0f, 0.0f, // bottom-left
					  0.0f,  (float)mHeight, 0.0f, 1.0f, // top-left
			 (float)mWidth,  (float)mHeight, 1.0f, 1.0f, // top-right
			 (float)mWidth,            0.0f, 1.0f, 0.0f  // bottom-right
		};

		unsigned indices[]
		{
			0, 1, 2, //upper-left triangle 
			0, 2, 3 //bottom-left triangle 
		};

		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);
		glGenBuffers(1, &mEBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)8);
		glEnableVertexAttribArray(1);

		//----------------------------------------------TEXTURE--------------------------------------------------------//
		glGenTextures(1, &mTex);
		glBindTexture(GL_TEXTURE_2D, mTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	int OpenGLSprite::GetWidth() const
	{
		return mWidth;
	}
	int OpenGLSprite::GetHeight() const
	{
		return mHeight;
	}
	void OpenGLSprite::Bind()
	{
		glBindVertexArray(mVAO);
		glBindTexture(GL_TEXTURE_2D, mTex);
	}
	bool OpenGLSprite::IsBound() const
	{
		return false;
	}
}