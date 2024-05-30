/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Enemy.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"

class Enemy : public Object
{
public:
    Enemy() = default;
	Enemy(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Enemy() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override;

	void SetHp(float amount) { hp = amount;}
	void SetMaxHp(float amount) { MaxHp = amount; }
	float GetHp() { return hp; }
	float GetMaxHp() { return MaxHp; }

	void SetScore(int amount) { score = amount; }
	int GetScore() { return score; }

	void SetIsHit(bool state) { isHit = state; }
	void SetInvincibleState(bool state) { isInvincible = state;}
	bool GetInvincibleState() { return isInvincible; }

	glm::vec2 GetSpawnPosition() { return spawnPosition; }
	void SetSpawnPosition(glm::vec2 pos) { spawnPosition = pos; }
	void SetAngleToTarget(Object* target);

	bool GetIsGround() { return isGround; }
	void SetIsGround(bool state) { isGround = state; }

	void Hit(float dt);
	void Death(float dt);
protected:

	float hp = 1;
	float MaxHp = 1;
	int score = 10;

	float invincibleDelay = 0.f;

	bool isHit = false;
	bool isInvincible = false;
	bool isInCamera = false;
	bool isGround = false;

	glm::vec2 spawnPosition = { 0.f,0.f };
};