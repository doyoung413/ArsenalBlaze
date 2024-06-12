/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyBigA.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Enemy.hpp"

class EnemyBigA : public Enemy
{
public:
	EnemyBigA() = default;
	EnemyBigA(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_ = { 0.f,0.f }, glm::vec2 stopPositionOffset_ = {0.f,0.f});
	~EnemyBigA() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override { Enemy::CollideObject(obj); };

	void SetMoveReverse(bool reverse_ = false);
protected:
	float stopDelay = 0.0f;
	
	float direction = -1.f;
	bool turningPoint = false;
};