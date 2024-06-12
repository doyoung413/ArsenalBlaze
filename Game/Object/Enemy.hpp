/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Enemy.hpp
//Description: Header file for enemy's object class
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"
#include "Object/EnemyType.hpp"

class Enemy : public Object
{
public:
    Enemy() = default;
	Enemy(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name);
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

	void SetAngleToTarget(Object* target);

	bool GetIsGround() { return isGround; }
	void SetIsGround(bool state) { isGround = state; }

	bool GetIsReadyToFight() { return isReadyToFight; }
	void SetIsReadyToFight(bool state) { isReadyToFight = state; }

	float GetReverse() { return reverse; }
	glm::vec2 GetSpawnPositionOffset() { return spawnPositionOffset; }
	glm::vec2 GetStopPositionOffset() { return stopPositionOffset; }

	EnemyType GetEnemyType() { return enemyTypes; }

	void Hit(float dt);
	void Death(float dt);
protected:

	float hp = 1;
	float MaxHp = 1;
	int score = 10;

	float invincibleDelay = 0.f;

	bool isReadyToFight = true;
	bool isHit = false;
	bool isInvincible = false;
	bool isInCamera = false;
	bool isGround = false;
	float reverse = 1.f;

	glm::vec2 viewSize = { 0.f,0.f };
	glm::vec2 cameraCenter = { 0.f,0.f };

	glm::vec2 spawnPosition = { 0.f,0.f };
	glm::vec2 spawnPositionOffset = { 0.f,0.f };
	glm::vec2 stopPositionOffset = { 0.f,0.f };

	EnemyType enemyTypes = EnemyType::NONE;
};