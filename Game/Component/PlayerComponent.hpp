/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: PlayerComponent.hpp
//Description: Header file for component for player
/*-------------------------------------------------------*/
#pragma once
#include "Component.hpp"
#include "Object/Player.hpp"

struct KeySet;
class PlayerComponent : public Component
{
public:
	PlayerComponent();
	~PlayerComponent() override;

	void Init() override;
	void Update(float dt) override;
	void End() override {};

	void SetInvincibleState(bool state) { isInvincible = state; }
	bool GetInvincibleState() { return isInvincible; }

	void SetMaxSubShotDelay(float maxDelay);

	void Attack();
	void SubAttack();
private:
	void Input(float dt);
	void Delay(float dt);

	void SpawnBarrier();
	void ClearBarrier();

	glm::vec2 windowSize = { 0.f,0.f };
	glm::vec2 cameraCenter = { 0.f,0.f };

	float playerMoveSpeed = 7.f;

	float maxShotDelay = 10.f;
	float shotDelay = 0.0f;
	bool isShotReady = true;

	float maxSubShotDelay = 20.f;
	float subShotDelay = 0.0f;
	bool isSubShotReady = false;

	float invincibleDelay = 0.f;

	bool isInvincible = false;
	bool isHit = false;

	std::vector<Object*> barriers;
};