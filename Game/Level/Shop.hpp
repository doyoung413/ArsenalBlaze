#pragma once
#include "Level.hpp"
#include "Instance.hpp"

#include "Object/Player.hpp"
#include "Text/Text.hpp"

enum class ShopState
{
	WEAPON,
	EQUIPEMENT,
	MAIN
};

class Shop : public Level
{
public:
	Shop() = default;
	~Shop() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;

	void Input();
private:
	void ShopMain();
	void WeaponShop();
	void EquipmentShop();

	void WeaponUpgrade();
	void EquipmentUpgrade();
	bool Buy(int cost);

	Text text;

	int selectionIndex = 0;
	float warningDelay = 0.f;
	bool isWarningOn = false;

	SpriteManager* spriteManager = nullptr;
	GameManager* gameManager = nullptr;
	ObjectManager* objectManager = nullptr;
	SoundManager* soundManager = nullptr;
	InputManager* inputManager = nullptr;

	ShopState shopState = ShopState::MAIN;
	Player* player = nullptr;
};