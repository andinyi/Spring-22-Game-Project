#include "Entity.h"
#include <vector>
#include "Indev.h"


Entity::Entity(const std::vector<std::string>& filename) : mImage(filename.begin(), filename.end())
{

}

int Entity::GetX() const
{
	return mXPos;
}

int Entity::GetY() const
{
	return mYPos;
}

int Entity::GetZ() const
{
	return mZPos;
}

bool Entity::GetSolid() const
{
	return mSolid;
}

int Entity::GetActiveImage() const
{
	return mActiveImage;
}

int Entity::GetWidth() const
{
	return mImage[mActiveImage].GetWidth();
}

int Entity::GetHeight() const
{
	return mImage[mActiveImage].GetHeight();
}

void Entity::SetX(int newX)
{
	mXPos = newX;
}

void Entity::SetY(int newY)
{
	mYPos = newY;
}

void Entity::SetZ(int newZ)
{
	mZPos = newZ;
}

void Entity::SetSolid(bool newSolid)
{
	mSolid = newSolid;
}

void Entity::SetActiveImage(int newImage)
{
	mActiveImage = newImage;
}

void Entity::Draw()
{
	Indev::Renderer::Draw(mImage[mActiveImage], mXPos, mYPos, mZPos);
}
