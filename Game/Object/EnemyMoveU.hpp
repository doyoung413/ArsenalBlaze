/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyMoveU.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Enemy.hpp"

class EnemyMoveU : public Enemy
{
public:
	EnemyMoveU() = default;
	EnemyMoveU(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name,  glm::vec2 spawnPositionOffset_ = { 0.f,0.f }, glm::vec2 stopPositionOffset_ = { 0.f,0.f });
	~EnemyMoveU() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override { Enemy::CollideObject(obj); };

	void SetMoveReverse(bool reverse_ = false);
protected:
	void SetRotate(float dt, float increase, float maxDelay, float max);
	float rotateDelay = 0.0f;
	float stopDelay = 0.0f;
	
	float direction = -1.f;
	bool turningPoint = false;
};