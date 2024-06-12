/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyTowardA.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyTowardA.hpp"
#include "Component/Physics.hpp"
#include "Component/EnemyAttack.hpp"

EnemyTowardA::EnemyTowardA(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { positionX, viewSize.y / 2.f + height };

	GetComponent<Physics>()->SetAcceleration({ 0.f, 0.75f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 0.f, 8.f });

	AddComponent<EnemyAttack>();
	GetComponent<EnemyAttack>()->AddAttack(NORMALSHOT, 0.f, -6.f, 30.f, { 0.f, 0.f }, true);
	GetComponent<EnemyAttack>()->AddAttack(NORMALSHOT, 1.5f, -6.f, 30.f, { 0.f, 0.f }, true);
	GetComponent<EnemyAttack>()->AddAttack(NORMALSHOT, 3.f, -6.f, 30.f, { 0.f, 0.f }, true);
	GetComponent<EnemyAttack>()->AddAttack(NORMALSHOT, -3.f, -6.f, 30.f, { 0.f, 0.f }, true);
	GetComponent<EnemyAttack>()->AddAttack(NORMALSHOT, -1.5f, -6.f, 30.f, { 0.f, 0.f }, true);
	GetComponent<EnemyAttack>()->SetIsCanAttack(false);

	Enemy::SetHp(10.f);
	Enemy::SetMaxHp(10.f);

	enemyTypes = EnemyType::TOAWRD_A;
}

void EnemyTowardA::Init()
{
}

void EnemyTowardA::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		if (turningPoint == true)
		{
			stopDelay += dt;

			if (stopDelay > 15.f && stopDelay < 60.f)
			{
				GetComponent<Physics>()->Move(0.0f, 0.f, dt);
			}
			else if (stopDelay > 60.f)
			{
				GetComponent<Physics>()->Move(0.0f, -0.75f, dt);
			}
			else
			{
				GetComponent<Physics>()->Move(0.0f, 0.75f, dt);
			}
		}
		else if (GetPosition().y < (viewSize.y / 4.f) + cameraCenter.y + stopPositionOffset.y && turningPoint == false)
		{
			turningPoint = true;
			GetComponent<Physics>()->SetFriction(0.9f);
			GetComponent<EnemyAttack>()->SetIsCanAttack(true);
		}
		else
		{
			GetComponent<Physics>()->Move(0.f, -1.f, dt);
		}

	}
}