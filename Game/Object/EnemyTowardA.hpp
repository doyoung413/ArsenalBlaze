/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyTowardA.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Enemy.hpp"

class EnemyTowardA : public Enemy
{
public:
	EnemyTowardA() = default;
	EnemyTowardA(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, glm::vec2 spawnPositionOffset_ = { 0.f,0.f }, glm::vec2 stopPositionOffset_ = {0.f,0.f});
	~EnemyTowardA() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override { Enemy::CollideObject(obj); };
protected:
	float stopDelay = 0.0f;
	float moveDelay = 0.f;
	glm::vec2 preSpeed = { 0.f,0.f };
	
	bool turningPoint = false;
};