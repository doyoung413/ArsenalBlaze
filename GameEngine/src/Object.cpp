/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Object.cpp
//Description: Source file for basic object class
/*-------------------------------------------------------*/
#include "Object.hpp"
#include "Instance.hpp"

#include <iostream>

Object::Object(float positionX, float positionY, float speedX, float speedY, float width, float height,
	DrawType drawType, std::string name, ObjectType objectType)
{
	position.x = positionX;
	position.y = positionY;
	speed.x = speedX;
	speed.y = speedY;

	size.x = width;
	size.y = height;

	this->drawType = drawType;
	this->objectType = objectType;

	objectName = name;
	SetDepth(0.5f);
}

void Object::Init()
{
}

void Object::Update(float dt)
{
	for (auto& comp : componentList)
	{
		comp->Update(dt);
	}
	Draw(dt);
}

void Object::Draw(float dt)
{
	switch (drawType)
	{
	case DrawType::RECTANGLE:
		Instance::GetSpriteManager()->DrawRectangle(position, angle, size, color, depth);
		break;
	case DrawType::RECTANGLELINE:
		Instance::GetSpriteManager()->DrawRectangleLine(position, angle, size, color, depth);
		break;
	case DrawType::SPRITE:
		Instance::GetSpriteManager()->DrawSprite(spriteName, position, angle, size, color, depth);
		break;
	case DrawType::SPRITEANIMATION:
		Instance::GetSpriteManager()->DrawSpriteWithAnimation(spriteName, individualAnimation, dt, position, angle, size, color, depth);
		break;
	}
}

void Object::SetRotate(float value)
{
	if (value >= 360.f)
	{
		angle = value - 360.f;

	}
	else if (value < 0.f)
	{
		angle = 360.f + value;
	}
	else
	{
		angle = value;
	}
}

void Object::SetSpriteName(std::string name)
{
	spriteName = name;
	if (Instance::GetSpriteManager()->GetSprite(name)->isAnimated == true)
	{
		drawType = DrawType::SPRITEANIMATION;
		individualAnimation = Instance::GetSpriteManager()->GetSprite(name)->animation;
	}
	else
	{
		drawType = DrawType::SPRITE;
	}
}

bool Object::isEdgeOfCamera() noexcept
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x),
		static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();

	if (!(position.x + size.x < -(windowSize.x / 2.f + cameraCenter.x) || (windowSize.x / 2.f + cameraCenter.x) < position.x - size.x 
		|| position.y + size.y < -(windowSize.y / 2.f + cameraCenter.y) || (windowSize.y / 2.f + cameraCenter.y) < position.y - size.y))
	{
		return true;
	}
	return false;
}

bool Object::isInOfCamera() noexcept
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x),
		static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();
	if (position.x - (size.x) < (windowSize.x / 2.f + cameraCenter.x) && position.x + (size.x) > -(windowSize.x / 2.f - cameraCenter.x)
		&& position.y - (size.y) < (windowSize.y / 2.f + cameraCenter.y) && position.y + (size.y) > -(windowSize.y / 2.f - cameraCenter.y))
	{
		return true;
	}
	return false;
}

bool Object::isOutOfCamera() noexcept
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x),
		static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();
	if (position.x > (windowSize.x / 2.f + cameraCenter.x) + (size.x) || position.x < -(windowSize.x / 2.f - cameraCenter.x) - (size.x)
		|| position.y >(windowSize.y / 2.f + cameraCenter.y) + (size.y) || position.y < -(windowSize.y / 2.f - cameraCenter.y) - (size.y))
	{
		return true;
	}
	return false;
}

bool Object::isOutOfWindowHigh() noexcept
{
	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();
	if (position.y > (windowSize.y / 2.f + cameraCenter.y) + (size.y))
	{
		return true;
	}
	return false;
}

void Object::DestroyAllComponents()
{
	for (auto* comp : componentList)
	{
		delete comp;
	}
	componentList.clear();
}
