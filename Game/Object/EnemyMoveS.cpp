/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyMoveS.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyMoveS.hpp"
#include "Component/Physics.hpp"

EnemyMoveS::EnemyMoveS(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { viewSize.x / 6.f * 3.f , viewSize.y / 2.f + height };

	GetComponent<Physics>()->SetAcceleration({ 8.f, 0.75f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 8.f, 0.75f });

	Enemy::SetHp(0.1f);
	Enemy::SetMaxHp(0.1f);

	enemyTypes = EnemyType::MOVE_S;
}

void EnemyMoveS::Init()
{
}

void EnemyMoveS::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		if ((direction == -1 && position.x < -(viewSize.x / 6.f * 3.f)) || (direction == 1 && position.x > (viewSize.x / 6.f * 3.f)))
		{
			direction *= -1.f * reverse;
		}
		GetComponent<Physics>()->Move(direction * 8.0f, -0.75f, dt);
	}
}

void EnemyMoveS::SetMoveReverse(bool reverse_)
{
	if (reverse_ == true)
	{
		reverse *= -1.f;
		spawnPosition.x = -spawnPosition.x;
	}
}
