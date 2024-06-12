#include "GameManager.hpp"
#include "Instance.hpp"

void GameManager::Init()
{
}

void GameManager::AddHp(int hp_)
{
	playerState.hp += hp_;
	playerState.hp = std::clamp(playerState.hp, 0, playerState.MaxHp);
}

void GameManager::SetWeaponPower(PlayerWeapon weapon, int powerLevel)
{
	switch (weapon)
	{
	case PlayerWeapon::LASER:
		playerState.weaponPower.laser = powerLevel;
		break;
	case PlayerWeapon::HOMING:
		playerState.weaponPower.homing = powerLevel;
		break;
	}
}
