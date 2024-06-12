/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyRobotA.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyRobotA.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"
#include "Component/EnemyAttack.hpp"

EnemyRobotA::EnemyRobotA(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { (reverse * (-viewSize.x / 2.f)) + cameraCenter.x + (reverse * (-width))
		, cameraCenter.y + (viewSize.y / 3.f) };

	GetComponent<Physics>()->SetAcceleration({ 1.0f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 3.f, 8.f });

	AddComponent<EnemyAttack>();
	GetComponent<EnemyAttack>()->AddAttack(TOWARD_PLAYER_SPREAD360, 8.f, 8.f, 100.f, { 0.f, 0.f }, false, 8, 0.f, 40.f);
	GetComponent<EnemyAttack>()->SetIsCanAttack(false);

	Enemy::SetHp(20.f);
	Enemy::SetMaxHp(20.f);

	enemyTypes = EnemyType::ROBOT_A;
}

void EnemyRobotA::Init()
{
}

void EnemyRobotA::Update(float dt)
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
			SetAngleToTarget(Instance::GetObjectManager()->FindObjectWithName("Player"));
			GetComponent<Physics>()->Move(reverse * 1.f, -0.f, dt);
		}
		else if (turningPoint == true)
		{
			stopDelay += dt;
			if (stopDelay > 300.f)
			{
				GetComponent<EnemyAttack>()->SetIsCanAttack(false);
				GetComponent<Physics>()->Move(0.0f, 0.25f, dt);
			}
			else
			{
				SetAngleToTarget(Instance::GetObjectManager()->FindObjectWithName("Player"));
				GetComponent<Physics>()->Move(0.0f, 0.0f, dt);
			}
		}
	}
}

void EnemyRobotA::SetMoveReverse(bool reverse_)
{
	if (reverse_ == true)
	{
		reverse *= -1.f;
		spawnPosition.x = -spawnPosition.x;
	}
}
