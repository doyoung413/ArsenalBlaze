/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyMoveU.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyMoveU.hpp"
#include "Component/Physics.hpp"

EnemyMoveU::EnemyMoveU(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { positionX , viewSize.y / 2.f + height };

	GetComponent<Physics>()->SetAcceleration({ 2.0f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 7.5f, 7.5f });

	Enemy::SetHp(0.1f);
	Enemy::SetMaxHp(0.1f);

	enemyTypes = EnemyType::MOVE_U;
}

void EnemyMoveU::Init()
{
}

void EnemyMoveU::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		if (GetPosition().y <= cameraCenter.y + spawnPositionOffset.y && turningPoint == false)
		{
			turningPoint = true;
		}
		else if (GetPosition().y <= (viewSize.y / 4.f) + cameraCenter.y + spawnPositionOffset.y && turningPoint == false)
		{
			if (reverse == -1.f)
			{
				SetRotate(dt, 15.f, 0.5f, 180.f);
			}
			else
			{
				SetRotate(dt, -15.f, 0.5f, 45.f);
			}
			GetComponent<Physics>()->Move(reverse * 0.5f, -1.0f, dt);
		}
		else if (GetPosition().y >= (viewSize.y / 8.f) + cameraCenter.y + spawnPositionOffset.y && turningPoint == true)
		{
			if (reverse == -1.f)
			{
				SetRotate(dt, 15.f, 0.5f, 270.f);
			}
			else
			{
				SetRotate(dt, -15.f, 0.5f, -90.f);
			}
			GetComponent<Physics>()->Move(0.f, 1.0f, dt);
		}
		else if (turningPoint == true)
		{
			stopDelay += dt;
			if (stopDelay > 40.f)
			{
				if (reverse == -1.f)
				{
					SetRotate(dt, 15.f, 0.5f, 45.f);
				}
				else
				{
					SetRotate(dt, -15.f, 0.5f, -45.f);
				}
				GetComponent<Physics>()->Move(reverse * 0.5f, 1.0f, dt);
			}
			else
			{
				if (reverse == -1.f)
				{
					SetRotate(dt, 15.f, 0.5f, 180.f);
				}
				else
				{
					SetRotate(dt, -15.f, 0.5f, 0.f);
				}
				GetComponent<Physics>()->Move(reverse * 0.3f, 0.f, dt);
			}
		}
		else
		{
			Object::SetRotate(90.f);
			GetComponent<Physics>()->Move(0.f, -1.f, dt);
		}
	}
}

void EnemyMoveU::SetMoveReverse(bool reverse_)
{
	if (reverse_ == true)
	{
		reverse *= -1.f;
		spawnPosition.x = -spawnPosition.x;
	}
}

void EnemyMoveU::SetRotate(float dt, float increase, float maxDelay, float max)
{
	if (GetRotate() != max)
	{
		rotateDelay += 0.1f * dt;
		if (rotateDelay >= maxDelay)
		{
			rotateDelay = 0;
			Object::SetRotate(GetRotate() + increase);
		}
	}
}
