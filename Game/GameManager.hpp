#pragma once
#include "InputKeys.hpp"
#include "Text/Text.hpp"

#include "glm.hpp"

enum class GameMode
{
	RUNNING,
	EDITOR,
};

enum class PlayerWeapon
{
	NONE,
	NORMAL,
	LASER,
	HOMING,
};

struct WeaponPower
{
	int normal = 0;
	int laser = 0;
	int homing = 0;
};

struct PlayerState
{
	int money = 1000;
	int MaxHp = 50;
	int hp = 50;

	PlayerWeapon weapons[2] = { PlayerWeapon::NORMAL, PlayerWeapon::NORMAL };
	int currentWeaponIndex = 0;
	bool isBarrier = false;
	WeaponPower weaponPower;
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
	void DrawUI(float dt);

	void SetScrollSpeed(glm::vec2 amount) { ScrollSpeed = amount; }
	glm::vec2 GetScrollSpeed() { return ScrollSpeed; }

	void AddScore(int amount) { score += amount; }

	GameMode GetGameMode() { return gameMode; }
	void SetGameMode(GameMode mode) { gameMode = mode; }
	void SetMaxHp(int hp_) { playerState.MaxHp = hp_; }
	int GetMaxHp() { return playerState.MaxHp; }

	void AddHp(int hp_);
	int GetHp() { return playerState.hp; }

	void SetMoney(int money_) { playerState.money = money_; }
	int GetMoney() { return playerState.money; }

	PlayerWeapon GetPlayerWeapon() { return playerState.weapons[playerState.currentWeaponIndex]; }
	void SetPlayerWeapon(PlayerWeapon weapon_) { playerState.weapons[playerState.currentWeaponIndex] = weapon_; }
	void SetWeaponPower(PlayerWeapon weapon, int powerLevel);
	WeaponPower GetWeaponPower() { return playerState.weaponPower; }

	void SwitchWeapon();

	void SetIsBarrier(bool state) { playerState.isBarrier = state; }
	bool GetIsBarrier() { return playerState.isBarrier; }

	void SetIsPlayerCanControl(bool state) { isPlayerCanControl = state; }
	bool GetIsPlayerCanControl() { return isPlayerCanControl; }

	KeySet& GetKeySetting() { return set; }
private:
	void DrawSubWeaponState(float dt);

	int score = 0;

	glm::vec2 subWeapon1Pos = { 0.f,0.f };
	glm::vec2 subWeapon2Pos = { 0.f,0.f };

	glm::vec2 viewSize = { 0.f,0.f };
	glm::vec2 ScrollSpeed = { 0.f, 0.f };

	glm::vec2 maxHpBarSize = { 232.f, 32.f };
	glm::vec2 hpBarSize = { 232.f, 32.f };

	GameMode gameMode = GameMode::RUNNING;

	bool isPlayerCanControl = true;
	bool isPlayerCanSwitchWeapon = true;

	PlayerState playerState;
	KeySet set;
	Text text;
};