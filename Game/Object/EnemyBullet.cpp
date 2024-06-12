/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyBullet.cpp
//Description: Source file for enemy's bullet object class
/*-------------------------------------------------------*/
#include "EnemyBullet.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"

#include <iostream>

EnemyBullet::EnemyBullet(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, ObjectType::ENEMYBULLET)
{
	AddComponent<Physics>();
	GetComponent<Physics>()->Init({ width, height });
}

void EnemyBullet::Init()
{
}

void EnemyBullet::Update(float dt)
{
	Object::Update(dt);
	position.x += speed.x * dt;
	position.y += speed.y * dt;

	if (isOutOfCamera())
	{
		Instance::GetObjectManager()->Destroy(id);
	}
}
