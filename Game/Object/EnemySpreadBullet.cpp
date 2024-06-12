/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemySpreadBullet.cpp
//Description: Source file for enemy's bullet object class
/*-------------------------------------------------------*/
#include "EnemySpreadBullet.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"

#include <iostream>

EnemySpreadBullet::EnemySpreadBullet(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, float shotDelayMax, int numBullets_, float spreadBulletSpeed_)
	: EnemyBullet(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	delayMax = shotDelayMax;
	numBullets = numBullets_;
	spreadBulletSpeed = spreadBulletSpeed_;
	isBreakableToHit = false;
}

void EnemySpreadBullet::Init()
{
}

void EnemySpreadBullet::Update(float dt)
{
	Object::Update(dt);
	position.x += speed.x * dt;
	position.y += speed.y * dt;

	delay += dt;
	if (delay > delayMax)
	{
		float angleStep = 360.0f / numBullets;
		for (int i = 0; i < numBullets; i++)
		{
			float currentAngle = angleStep * i;
			float radians = currentAngle * 3.14f / 180.0f;
			Instance::GetObjectManager()->AddObject<EnemyBullet>(position.x, position.y,
				spreadBulletSpeed * cos(radians), spreadBulletSpeed * sin(radians), size.x / 2.f, size.y / 2.f, DrawType::RECTANGLE, "EnemyBullet");
			std::cout << spreadBulletSpeed * cos(radians) << std::endl;
		}
		Instance::GetObjectManager()->Destroy(id);
	}
	if (isOutOfCamera())
	{
		Instance::GetObjectManager()->Destroy(id);
	}
}
