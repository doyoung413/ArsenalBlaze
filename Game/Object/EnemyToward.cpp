/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyToward.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "EnemyToward.hpp"
#include "Component/Physics.hpp"

EnemyToward::EnemyToward(float positionX, float positionY, float speedX, float speedY, float width, float height,  DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_, glm::vec2 stopPositionOffset_)
	: Enemy(positionX, positionY, speedX, speedY, width, height, drawType, name)
{
	Enemy::stopPositionOffset = stopPositionOffset_;
	Enemy::spawnPositionOffset = spawnPositionOffset_;
	spawnPosition = { positionX, viewSize.y / 2.f + height };

	GetComponent<Physics>()->SetAcceleration({ 0.f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 0.f, 8.f });

	enemyTypes = EnemyType::TOWARD;
}

void EnemyToward::Init()
{
}

void EnemyToward::Update(float dt)
{
	Enemy::Update(dt);
	if (isInCamera == true)
	{
		GetComponent<Physics>()->Move(0.f, -0.5f, dt);
	}
}
