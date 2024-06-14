#include "GameManager.hpp"
#include "Instance.hpp"

void GameManager::Init()
{
	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(Instance::GetSpriteManager()->GetShader());

	viewSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	subWeapon1Pos = { -272.f, -128.f };
	subWeapon2Pos = { -208.f, -192.f };
	SetIsBarrier(true);
}

void GameManager::DrawUI(float dt)
{
	text.DrawTextWithColor("SCORE", -viewSize.x / 2.f, viewSize.y / 2.f - 32.f, 0.f, 1.5f, { 1.f, 1.f, 1.f, 1.f });
	text.DrawTextWithColor(std::string(static_cast<size_t>(8) - std::to_string(score).size(), '0') + std::to_string(score), -viewSize.x / 2.f, viewSize.y / 2.f - 64.f, 0.f, 1.5f, { 1.f, 1.f, 1.f, 1.f });

	//Instance::GetSpriteManager()->DrawHPBar("HpBar", playerState.hp, playerState.MaxHp, { cameraCenter.x - viewSize.x / 2.f, viewSize.y / 2.f - 8.f, 0.f }, 0.f, { hpBarSize, 0.f }, 1.f, 1.f);
	//Instance::GetSpriteManager()->DrawSprite("HpBar1", { UIPosition.x + cameraCenter.x - windowSize.x / 2.f + 8.f + maxHpBarSize.x / 2.f ,  UIPosition.y - 8.f + maxHpBarSize.y / 2.f, 0.f }, 0.f, { maxHpBarSize / 2.f, 0.f }, 1.f, 1.f);
	DrawSubWeaponState(dt);
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

void GameManager::SwitchWeapon()
{
	if (isPlayerCanSwitchWeapon == true)
	{
		switch (playerState.currentWeaponIndex)
		{
		case 0:
			playerState.currentWeaponIndex = 1;
			break;
		case 1:
			playerState.currentWeaponIndex = 0;
			break;
		}
		isPlayerCanSwitchWeapon = false;
	}
}

void GameManager::DrawSubWeaponState(float dt)
{/*
	subWeapon1Pos = { -272.f, -128.f };
	subWeapon2Pos = { -208.f, -192.f };*/

	if (isPlayerCanSwitchWeapon == false)
	{
		switch (playerState.currentWeaponIndex)
		{
		case 0:
			if (subWeapon2Pos.x < -208.f)
			{
				subWeapon2Pos.x += 5.f * dt;
				if (subWeapon2Pos.x > -208.f) 
					subWeapon2Pos.x = -208.f;
			}
			if (subWeapon2Pos.y > -192.f)
			{
				subWeapon2Pos.y -= 5.f * dt;
				if (subWeapon2Pos.y < -192.f) 
					subWeapon2Pos.y = -192.f;
			}
			if (subWeapon1Pos.x > -272.f)
			{
				subWeapon1Pos.x -= 5.f * dt;
				if (subWeapon1Pos.x < -272.f) 
					subWeapon1Pos.x = -272.f;
			}
			if (subWeapon1Pos.y < -128.f) {
				subWeapon1Pos.y += 5.f * dt;
				if (subWeapon1Pos.y > -128.f) 
					subWeapon1Pos.y = -128.f;
			}
			isPlayerCanSwitchWeapon = (subWeapon1Pos.x == -272.f && subWeapon1Pos.y == -128.f && subWeapon2Pos.x == -208.f && subWeapon2Pos.y == -192.f);
			break;
		case 1:
			if (subWeapon1Pos.x < -208.f)
			{
				subWeapon1Pos.x += 5.f * dt;
				if (subWeapon1Pos.x > -208.f) 
					subWeapon1Pos.x = -208.f;
			}
			if (subWeapon1Pos.y > -192.f)
			{
				subWeapon1Pos.y -= 5.f * dt;
				if (subWeapon1Pos.y < -192.f) 
					subWeapon1Pos.y = -192.f;
			}
			if (subWeapon2Pos.x > -272.f)
			{
				subWeapon2Pos.x -= 5.f * dt;
				if (subWeapon2Pos.x < -272.f) 
					subWeapon2Pos.x = -272.f;
			}
			if (subWeapon2Pos.y < -128.f) {
				subWeapon2Pos.y += 5.f * dt;
				if (subWeapon2Pos.y > -128.f) 
					subWeapon2Pos.y = -128.f;
			}
			isPlayerCanSwitchWeapon = (subWeapon2Pos.x == -272.f && subWeapon2Pos.y == -128.f && subWeapon1Pos.x == -208.f && subWeapon1Pos.y == -192.f);
		}
	}
	Instance::GetSpriteManager()->DrawRectangle({ subWeapon1Pos.x, subWeapon1Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, 1.f, 1.f);
	Instance::GetSpriteManager()->DrawRectangle({ subWeapon2Pos.x, subWeapon2Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, 0.5f, 1.f);
}
