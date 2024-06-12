/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyToward.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Enemy.hpp"

class EnemyToward : public Enemy
{
public:
	EnemyToward() = default;
	EnemyToward(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name,  glm::vec2 spawnPositionOffset_ = { 0.f,0.f }, glm::vec2 stopPositionOffset_ = { 0.f,0.f });
	~EnemyToward() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override { Enemy::CollideObject(obj); };
protected:
};