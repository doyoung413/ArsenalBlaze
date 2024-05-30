/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: PlayerComponent.hpp
//Description: Header file for component for player
/*-------------------------------------------------------*/
#pragma once
#include "Component.hpp"
#include "Object/Player.hpp"


class PlayerComponent : public Component
{
public:
	PlayerComponent() : Component(ComponentTypes::PLAYERCOMP) {}
	~PlayerComponent() override {};

	void Init() override;
	void Update(float dt) override;
	void End() override {};

	void SetInvincibleState(bool state) { isInvincible = state; }
	bool GetInvincibleState() { return isInvincible; }

	void Attack();
private:
	void Input(float dt);
	void Delay(float dt);

	glm::vec2 windowSize = { 0.f,0.f };
	glm::vec2 cameraCenter = { 0.f,0.f };

	float playerMoveSpeed = 7.f;

	float shotDelay = 0.0f;
	bool isShotReady = true;

	float invincibleDelay = 0.f;

	bool isInvincible = false;
	bool isHit = false;
};