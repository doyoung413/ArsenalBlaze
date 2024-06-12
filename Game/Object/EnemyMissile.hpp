#pragma once
#include "Object.hpp"

class EnemyMissile : public Object
{
public:
	EnemyMissile() = default;
	EnemyMissile(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~EnemyMissile() {};

	void Init() override;
	void Update(float dt) override;

	void SetHp(int amount) { hp = amount;}
	void SetMaxHp(int amount) { MaxHp = amount; }
	int GetHp() { return hp; }
	int GetMaxHp() { return MaxHp; }

	void SetScore(int amount) { score = amount; }
	int GetScore() { return score; }

	void SetInvincibleState(bool state) { isInvincible = state;}
	bool GetInvincibleState() { return isInvincible; }

	void SetAngleToTarget(Object* target);

	void SetDamage(int amount) { damage = amount; }
	int GetDamage() { return damage; }

protected:
	int hp = 2;
	int MaxHp = 2;
	int score = 5;
	int damage = 10;

	float delay = 0.f;
	float maxInvincibleDelay = 3.f;
	float invincibleDelay = 0.f;

	bool isInvincible = false;
	bool isInCamera = false;

	glm::vec2 spawnPosition = { 0.f,0.f };
};