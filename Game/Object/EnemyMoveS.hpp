/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyMoveS.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Enemy.hpp"

class EnemyMoveS : public Enemy
{
public:
	EnemyMoveS() = default;
	EnemyMoveS(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name,  glm::vec2 spawnPositionOffset_ = { 0.f,0.f }, glm::vec2 stopPositionOffset_ = { 0.f,0.f });
	~EnemyMoveS() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override { Enemy::CollideObject(obj); };

	void SetMoveReverse(bool reverse_ = false);
protected:
	float direction = -1.f;
};