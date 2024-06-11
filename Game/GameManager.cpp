#include "GameManager.hpp"
#include "Instance.hpp"

void GameManager::Init()
{
}

void GameManager::AddHp(int hp_)
{
	hp += hp_;
	hp = std::clamp(hp, 0, MaxHp);
}