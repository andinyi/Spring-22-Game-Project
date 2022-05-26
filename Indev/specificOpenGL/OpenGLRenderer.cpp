#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Indev
{
	void OpenGLRenderer::Draw(Indev::Sprite picture, int xPos, int yPos, int zPos, Indev::Shader shader)
	{
		int winWidth{ GameWindow::GetWindow()->GetWidth() };
		int winHeight{ GameWindow::GetWindow()->GetHeight() };

		shader.Bind();
		picture.Bind();

		//picture.Rotate(-100); //try to implement a rotate method, doesnt work so commenting out

		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void OpenGLRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}