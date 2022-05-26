#pragma once

#include "Indev.h"
#include <vector>

class Entity
{
public:
	Entity(const std::vector<std::string>& filename);
	int GetX() const;
	int GetY() const;
	int GetZ() const;
	bool GetSolid() const;
	int GetActiveImage() const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int newX);
	void SetY(int newY);
	void SetZ(int newZ);
	void SetSolid(bool newSolid);
	void SetActiveImage(int i);

	void Draw();

private:
	int mXPos{ 0 };
	int mYPos{ 0 };
	int mZPos{ 0 };

	bool mSolid{ true };

	int mActiveImage{ 0 };

	std::vector<Indev::Sprite> mImage;
};
