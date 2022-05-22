#pragma once

namespace Indev 
{
	class ShaderImplementation
	{
	public:
		virtual void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3) = 0;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) = 0;
		virtual void Bind() = 0;
	private:

	};
}