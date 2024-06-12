/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyBigA.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyBigA.hpp"
#include "Component/Physics.hpp"
#include "Component/EnemyAttack.hpp"

EnemyBigA::EnemyBigA(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { positionX, viewSize.y / 2.f + height };

	GetComponent<Physics>()->SetAcceleration({ 1.0f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 3.f, 8.f });

	AddComponent<EnemyAttack>();
	GetComponent<EnemyAttack>()->AddAttack(MISSILE, 0.f, -8.f, 48.f, { -64.f, 0.f });
	GetComponent<EnemyAttack>()->AddAttack(MISSILE, 0.f, -8.f, 48.f, { 64.f, 0.f });
	GetComponent<EnemyAttack>()->SetIsCanAttack(false);

	Enemy::SetHp(20.f);
	Enemy::SetMaxHp(20.f);

	enemyTypes = EnemyType::BIG_A;
}

void EnemyBigA::Init()
{
}

void EnemyBigA::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		if (turningPoint == false)
		{
			if (GetPosition().y < (viewSize.y / 3.f) + cameraCenter.y + stopPositionOffset.y && turningPoint == false)
			{
				turningPoint = true;
				GetComponent<EnemyAttack>()->SetIsCanAttack(true);
			}
			GetComponent<Physics>()->Move(0.f, -1.f, dt);
		}
		else if (turningPoint == true)
		{
			stopDelay += dt;
			if (stopDelay > 300.f)
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

void EnemyBigA::SetMoveReverse(bool reverse_)
{
	if (reverse_ == true)
	{
		reverse *= -1.f;
	}
}
