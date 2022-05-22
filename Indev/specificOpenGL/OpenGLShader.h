#pragma once
#include "ShaderImplementation.h"

namespace Indev
{
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		virtual void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3) override;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void Bind() override;
	
	private:
		unsigned int mShaderProgram;
	};
}

