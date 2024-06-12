/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemySideAppear.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemySideAppear.hpp"
#include "Component/Physics.hpp"
#include "Component/EnemyAttack.hpp"

EnemySideAppear::EnemySideAppear(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { (reverse * (-viewSize.x / 2.f)) + cameraCenter.x + (reverse * (-width))
		, cameraCenter.y + (viewSize.y / 3.f) };

	GetComponent<Physics>()->SetAcceleration({ 2.0f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 8.f, 8.f });

	AddComponent<EnemyAttack>();
	GetComponent<EnemyAttack>()->AddAttack(TOWARD_PLAYER, 8.f, 8.f, 50.f);

	Enemy::SetHp(1.5f);
	Enemy::SetMaxHp(1.5f);

	enemyTypes = EnemyType::SIDE_APPEAR;
}

void EnemySideAppear::Init()
{
}

void EnemySideAppear::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		float stopPostion = (reverse * (-(viewSize.x / 3.5f))) + stopPositionOffset.x;
		if (turningPoint == false)
		{
			if (GetPosition().x >= stopPostion && reverse != -1.f)
			{
				turningPoint = true;
				GetComponent<EnemyAttack>()->SetIsCanAttack(true);
			}
			else if (GetPosition().x <= stopPostion && reverse == -1.f)
			{
				turningPoint = true;
				GetComponent<EnemyAttack>()->SetIsCanAttack(true);
			}
			GetComponent<Physics>()->Move(reverse * 1.f, -0.f, dt);
		}
		else if (turningPoint == true)
		{
			stopDelay += dt;
			if (stopDelay > 50.f)
			{
				GetComponent<EnemyAttack>()->SetIsCanAttack(false);
				GetComponent<Physics>()->Move(0.0f, -0.5f, dt);
			}
			else
			{
				GetComponent<Physics>()->Move(0.0f, 0.0f, dt);
			}
		}
	}
}

void EnemySideAppear::SetMoveReverse(bool reverse_)
{
	if (reverse_ == true)
	{
		reverse *= -1.f;
		spawnPosition.x = -spawnPosition.x;
	}
}
