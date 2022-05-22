#pragma once
#include "IndevUtility.h"
#include "ShaderImplementation.h"

namespace Indev
{
	class INDEV_API Shader
	{
	public: 
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3);
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void Bind();
	
	private:
		ShaderImplementation* mImplementation;

#ifdef USE_OPENGL
		OpenGLSHader* ptr;
#elif defined USE_DIRECTX
		DirectXShader* ptr;
#endif


	};
}
