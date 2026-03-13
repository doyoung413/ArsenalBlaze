#include "GameManager.hpp"
#include "Instance.hpp"

void GameManager::Init()
{
	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(Instance::GetSpriteManager()->GetShader());

	viewSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	subWeapon1Pos = { -272.f, -128.f };
	subWeapon2Pos = { -208.f, -192.f };
}

void GameManager::Update(float dt)
{
	if (playerState.hp <= 0 && Instance::GetLevelManager()->GetGameState() != State::PAUSE)
	{
		if (overDelay == 0.f)
		{
			ScrollSpeed.y = 0.f;
			int amount = 20;
			for (int i = 0; i < amount; i++)
			{
				float colorG = static_cast<float>(rand() % (9 - 3 + 1) + 3) * 0.1f;
				float pSize = static_cast<float>(rand() % (5 - 1 + 1) + (1));

				glm::vec2 newVel = { static_cast<float>(rand() % (5 - (-5) + 1) + (-5)) , (static_cast<float>(rand() % ((5) - (-5) + 1) + (-5))) };
				float lifeTime = static_cast<float>(rand() % (30 - 15 + 1) + 15);
				Instance::GetParticleManager()->AddSingleParticle(Instance::GetObjectManager()->FindObjectWithName("Player")->GetPosition(), { pSize, pSize }, newVel, 0.f, lifeTime, { 1.f, colorG, 0.f,1.f }, ParticleType::REC, "", 0.5f);
			}
			Instance::GetObjectManager()->Destroy(Instance::GetObjectManager()->FindObjectWithName("Player")->GetId());
		}
		overDelay +=  dt;
		text.DrawTextWithColor("GAME OVER", -112.f, 0.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		if (overDelay > 150.f)
		{
			overDelay = 0.f;
			PlayerState init;
			playerState = init;
			Instance::GetLevelManager()->ChangeLevel(LevelType::TITLE);
		}
	}
	hpBarSize.x = maxHpBarSize.x * (static_cast<float>(playerState.hp) / static_cast<float>(playerState.MaxHp));
	DrawUI(dt);
}

void GameManager::DrawUI(float dt)
{
	text.DrawTextWithColor("SCORE", -viewSize.x / 2.f, viewSize.y / 2.f - 32.f, 0.f, 1.5f, { 1.f, 1.f, 1.f, 1.f });
	text.DrawTextWithColor(std::string(static_cast<size_t>(8) - std::to_string(score).size(), '0') + std::to_string(score), -viewSize.x / 2.f, viewSize.y / 2.f - 64.f, 0.f, 1.5f, { 1.f, 1.f, 1.f, 1.f });

	glm::vec2 camCenter = Instance::GetCameraManager()->GetCenter();
	Instance::GetSpriteManager()->DrawHPBar("HpBar", playerState.hp, playerState.MaxHp, { camCenter.x - viewSize.x / 2.f, camCenter.y + viewSize.y / 2.f - 96.f, 0.f }, 0.f, { hpBarSize, 0.f }, 1.f, 1.f);
	Instance::GetSpriteManager()->DrawSprite("HpBar1", { camCenter.x - viewSize.x / 2.f + maxHpBarSize.x / 2.f, camCenter.y + viewSize.y / 2.f - 80.f, 0.f }, 0.f, { maxHpBarSize / 2.f, 0.f }, 1.f, 1.f);
	DrawSubWeaponState(dt);
}

void GameManager::AddHp(int hp_)
{
	playerState.hp += hp_;
	playerState.hp = std::clamp(playerState.hp, 0, playerState.MaxHp);
}

void GameManager::SetWeaponLevel(PlayerWeapon weapon, int powerLevel)
{
	switch (weapon)
	{
	case PlayerWeapon::LASER:
		playerState.weaponLevel.laser = powerLevel;
		break;
	case PlayerWeapon::HOMING:
		playerState.weaponLevel.homing = powerLevel;
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

void GameManager::ResetKeySetting()
{
	set.UP = KEYBOARDKEYS::UP;
	set.DOWN = KEYBOARDKEYS::DOWN;
	set.LEFT = KEYBOARDKEYS::LEFT;
	set.RIGHT = KEYBOARDKEYS::RIGHT;
	set.KEY1 = KEYBOARDKEYS::Z;
	set.KEY2 = KEYBOARDKEYS::X;
	set.KEY3 = KEYBOARDKEYS::C;
	set.START = KEYBOARDKEYS::ENTER;
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
	switch (playerState.weapons[0])
	{
	case PlayerWeapon::LASER:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon1Pos.x, subWeapon1Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, {0.f,1.f,0.f,1.f}, 1.f);
		break;
	case PlayerWeapon::HOMING:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon1Pos.x, subWeapon1Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, { 0.f,0.f,1.f,1.f }, 1.f);
		break;
	default:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon1Pos.x, subWeapon1Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, 1.f, 1.f);
		break;
	}
	switch (playerState.weapons[1])
	{
	case PlayerWeapon::LASER:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon2Pos.x, subWeapon2Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, { 0.f,1.f,0.f,1.f }, 1.f);
		break;
	case PlayerWeapon::HOMING:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon2Pos.x, subWeapon2Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, { 0.f,0.f,1.f,1.f }, 1.f);
		break;
	default:
		Instance::GetSpriteManager()->DrawRectangle({ subWeapon2Pos.x, subWeapon2Pos.y, 0.f }, 0.f, { 24.f, 24.f, 0.f }, 1.f, 1.f);
		break;
	}
}
