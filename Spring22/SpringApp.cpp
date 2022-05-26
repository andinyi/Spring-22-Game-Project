#include "SpringApp.h"

SpringApp::SpringApp()
{
	SetKeyPressedCallback([this](Indev::KeyPressedEvent e) {
		switch (e.GetKeyCode())
		{
		case INDEV_KEY_SPACE:
			if (!start)
				start = true;
			vMovement = jumpSpeed;
			break;
		}
	});

	SetKeyReleasedCallback([this](const Indev::KeyReleasedEvent& e) {
		
		});

	mBird.SetX(350);
	mBird.SetY(300);
	message.SetX(300);
	message.SetY(150);
	score[0].SetX(22);
	background[1].SetX(288);
	background[2].SetX(576);
}

void SpringApp::OnUpdate()
{
	background[0].Draw();
	background[1].Draw();
	background[2].Draw();
	if(start)
	{
		if (vMovement > 1)
		{
			mBird.SetActiveImage(1);
		}
		else if ((vMovement <= 1) && (vMovement >= -1))
			mBird.SetActiveImage(0);
		else
			mBird.SetActiveImage(2);

		mBird.SetY(mBird.GetY() + vMovement);
		vMovement -= 0.2;
		mBird.Draw();
		if (noPipes)
		{
			SpawnPipe();
			SetNoPipes(false);
		}
		for (int i = 0; i < pipeCount; i++)
		{
			pipes[i].SetX(pipes[i].GetX() - 2);
			pipes[i].Draw();
			pipesDown[i].SetX(pipes[i].GetX() - 2);
			pipesDown[i].Draw();
			if ((pipes[i].GetX() < mBird.GetX() + 2) && (pipes[i].GetX() > mBird.GetX() - 1))
			{
				SetNoPipes(true);
				Counter();
			}

			if (Collide(mBird, pipes[i]))
			{
				exit(0);
			}
			if (Collide(mBird, pipesDown[i]))
			{
				exit(0);
			}
		}
		score1[tens].Draw();
		score[ones].Draw();
	}
	else
	{
		message.Draw();
		return;
	}
}

bool SpringApp::Collide(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };
	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };
	if ((anotherLeft <= oneLeft && oneLeft <= anotherRight) || (anotherLeft <= oneRight && oneRight <= anotherRight) || (oneLeft <= anotherLeft && anotherLeft <= oneRight))
	{
		collideX = true;
	}
	bool collideY{ false };
	if ((anotherBottom <= oneBottom && oneBottom <= anotherTop) || (anotherBottom <= oneTop && oneTop <= anotherTop) || (oneBottom <= anotherBottom && anotherBottom <= oneTop))
	{
		collideY = true;
	}

	return collideX && collideY;
}

void SpringApp::SpawnPipe()
{
	if (pipes.size() == pipeCount)
	{
		pipes.push_back({ {"../Indev/Assets/Images/pipe_up.png"} });
		pipesDown.push_back({ {"../Indev/Assets/Images/pipe_down.png"} });
	}
	srand(time(NULL));
	int x = rand() % 100 + 500;
	int y = rand() % 270 + (-250);
	pipes[pipeCount].SetX(x);
	pipes[pipeCount].SetY(y);
	pipesDown[pipeCount].SetX(x);
	pipesDown[pipeCount].SetY((600 + y) - 150); 
	pipeCount++;
}

void SpringApp::SetNoPipes(bool noP)
{
	noPipes = noP;
}

void SpringApp::Counter()
{
	if (ones < 9)
	{
		ones++;
	}
	else {
		ones = 0;
		tens++;
	}
	if (tens == 10)
	{
		exit(0);
	}
	score[ones].SetX(22);
}

