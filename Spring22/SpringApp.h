#pragma once

#include "Indev.h"
#include "Entity.h"

class SpringApp : public Indev::IndevApp
{
public:
	SpringApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);
	void SpawnPipe();
	void SetNoPipes(bool noP);
	void Counter();
private:
	Entity mBird{ {"../Indev/Assets/Images/blue_mid_flap.png", "../Indev/Assets/Images/blue_up_flap.png", "../Indev/Assets/Images/blue_down_flap.png"}};
	std::vector<Entity> pipes{ { {"../Indev/Assets/Images/pipe_up.png"} } };
	std::vector<Entity> pipesDown{ { {"../Indev/Assets/Images/pipe_down.png"} } };
	Entity message{ {"../Indev/Assets/Images/message.png"} };
	std::vector<Entity> score{ {{ "../Indev/Assets/Images/0.png" }}, {{ "../Indev/Assets/Images/1.png" }}, {{ "../Indev/Assets/Images/2.png" }}, 
	{{ "../Indev/Assets/Images/3.png" }}, {{ "../Indev/Assets/Images/4.png" }}, {{ "../Indev/Assets/Images/5.png" }}, {{ "../Indev/Assets/Images/6.png" }},
	{{ "../Indev/Assets/Images/7.png" }}, {{ "../Indev/Assets/Images/8.png" }}, {{ "../Indev/Assets/Images/9.png" }} };
	std::vector<Entity> score1{ {{ "../Indev/Assets/Images/0.png" }}, {{ "../Indev/Assets/Images/1.png" }}, {{ "../Indev/Assets/Images/2.png" }},
	{{ "../Indev/Assets/Images/3.png" }}, {{ "../Indev/Assets/Images/4.png" }}, {{ "../Indev/Assets/Images/5.png" }}, {{ "../Indev/Assets/Images/6.png" }},
	{{ "../Indev/Assets/Images/7.png" }}, {{ "../Indev/Assets/Images/8.png" }}, {{ "../Indev/Assets/Images/9.png" }} };
	std::vector<Entity> background{ {{"../Indev/Assets/Images/background.png"}}, {{"../Indev/Assets/Images/background.png"}}, {{"../Indev/Assets/Images/background.png"}} };

	float vMovement{ 0 };
	float jumpSpeed{ 4 };
	bool start = false;
	int pipeCount{ 0 };
	bool noPipes = true;
	int tens{ 0 };
	int ones{ 0 };
};