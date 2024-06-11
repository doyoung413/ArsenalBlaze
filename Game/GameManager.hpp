#pragma once
#include "InputKeys.hpp"
#include "glm.hpp"

enum class GameMode
{
	RUNNING,
	EDITOR,
};

enum class PlayerWeapon
{
	NONE,
	VALCAN,
	LASER,
	HOMING,
};

struct KeySet
{
	KEYBOARDKEYS UP = KEYBOARDKEYS::UP;
	KEYBOARDKEYS DOWN = KEYBOARDKEYS::DOWN;
	KEYBOARDKEYS LEFT = KEYBOARDKEYS::LEFT;
	KEYBOARDKEYS RIGHT = KEYBOARDKEYS::RIGHT;
	KEYBOARDKEYS KEY1 = KEYBOARDKEYS::Z;
	KEYBOARDKEYS KEY2 = KEYBOARDKEYS::X;
	KEYBOARDKEYS KEY3 = KEYBOARDKEYS::C;
	KEYBOARDKEYS START = KEYBOARDKEYS::ENTER;

	GAMEPADBUTTONS PAD_UP = GAMEPADBUTTONS::DPAD_UP;
	GAMEPADBUTTONS PAD_DOWN = GAMEPADBUTTONS::DPAD_DOWN;
	GAMEPADBUTTONS PAD_LEFT = GAMEPADBUTTONS::DPAD_LEFT;
	GAMEPADBUTTONS PAD_RIGHT = GAMEPADBUTTONS::DPAD_RIGHT;
	GAMEPADBUTTONS PAD_KEY1 = GAMEPADBUTTONS::X;
	GAMEPADBUTTONS PAD_KEY2 = GAMEPADBUTTONS::Y;
	GAMEPADBUTTONS PAD_KEY3 = GAMEPADBUTTONS::A;
	GAMEPADBUTTONS PAD_START = GAMEPADBUTTONS::START;
};

class GameManager
{
public:
	GameManager() {};
	~GameManager() {};

	void Init();

	void SetScrollSpeed(glm::vec2 amount) { ScrollSpeed = amount; }
	glm::vec2 GetScrollSpeed() { return ScrollSpeed; }

	void AddScore(int amount) { score += amount; }

	GameMode GetGameMode() { return gameMode; }
	void SetGameMode(GameMode mode) { gameMode = mode; }
	void SetMaxHp(int hp_) { MaxHp = hp_; }
	void AddHp(int hp_);
	int GetHp() { return hp; }

	void SetMoney(int money_) { money += money_; }
	int GetMoney() { return money; }

	PlayerWeapon GetPlayerWeapon() { return weapon; }
	void SetPlayerWeapon(PlayerWeapon weapon_) { weapon = weapon_; }
	void SetPlayerWeaponLater(PlayerWeapon weapon_) { weaponTemp = weapon_; }

	void SetIsPlayerCanControl(bool state) { isPlayerCanControl = state; }
	bool GetIsPlayerCanControl() { return isPlayerCanControl; }

	KeySet& GetKeySetting() { return set; }
private:
	int score = 0;
	int highScore = 0;

	int money = 0;

	int MaxHp = 50;
	int hp = 50;

	glm::vec2 ScrollSpeed = { 0.f, 0.f };

	GameMode gameMode = GameMode::RUNNING;
	PlayerWeapon weapon = PlayerWeapon::VALCAN;
	PlayerWeapon weaponTemp = PlayerWeapon::NONE;

	bool isPlayerCanControl = true;

	KeySet set;
};