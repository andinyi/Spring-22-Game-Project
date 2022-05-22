#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include "IndevUtility.h"

namespace Indev
{
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{

		//Vertex Shader
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// file read //
		std::string source;
		std::ifstream vertexInput{ vertexFile };

		while (vertexInput)
		{
			std::string line;
			std::getline(vertexInput, line);
			line.append("\n");
			source += line;
		}
		vertexInput.close();

		const char* cSource = source.c_str();
		glShaderSource(vertexShader, 1, &cSource, NULL);
		glCompileShader(vertexShader);
		//Error check
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR SHADER VERTEX COMPILATION FAILED\n" << infoLog << std::endl;
		}

		//Fragment Shader
		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		
		// file read //
		source.clear();
		std::ifstream fragmentInput{ fragmentFile };

		while (fragmentInput)
		{
			std::string line;
			std::getline(fragmentInput, line);
			line.append("\n");
			source += line;
		}

		fragmentInput.close();

		const char* fragSource = source.c_str();
		glShaderSource(fragmentShader, 1, &fragSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog << std::endl;
		}
		//Link Shaders
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);
		//check for linking errors
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR SHADER PROGRAM LINKING FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
	{
		int uniformLocation{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUseProgram(mShaderProgram);
		glUniform3i(uniformLocation, val1, val2, val3);
	}

	void OpenGLShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		int uniformLocation{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUseProgram(mShaderProgram);
		glUniform2i(uniformLocation, val1, val2);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(mShaderProgram);
	}
}
