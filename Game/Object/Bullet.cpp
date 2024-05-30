/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Bullet.cpp
//Description: Source file for player's bullet object class
/*-------------------------------------------------------*/
#include "Bullet.hpp"
#include "Instance.hpp"

#include "Component/Physics.hpp"


Bullet::Bullet(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::BULLET;
	Init();
	AddComponent<Physics>();
	GetComponent<Physics>()->Init({ width, height });
}

void Bullet::Init()
{
}

void Bullet::Update(float dt)
{
	Object::Update(dt);
	GetComponent<Physics>()->Update(dt);

	position.x += speed.x * dt;
	position.y += speed.y * dt;

	if (isOutOfCamera())
	{
		Instance::GetObjectManager()->Destroy(id);
	}
}

