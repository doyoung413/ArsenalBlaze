#include "Shop.hpp"

#include "Component/PlayerComponent.hpp"
#include <string>

void Shop::Init()
{
	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(Instance::GetSpriteManager()->GetShader());

	player = new Player(128.f, 0.f, 0.f, 0.f, 46.f, 45.f, DrawType::SPRITE, "Player", ObjectType::PLAYER);
	player->SetSpriteName("Player");
	player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(100.f);
	Instance::GetGameManager()->SetIsPlayerCanControl(false);
	selectionIndex = 0;
}

void Shop::Update(float dt)
{
	switch (shopState)
	{
	case ShopState::MAIN:
		ShopMain();
		break;
	case ShopState::WEAPON:
		WeaponShop();
		player->Update(dt);
		break;
	case ShopState::EQUIPEMENT:
		EquipmentShop();
		break;
	}
	text.DrawTextWithColor("MONEY " + std::to_string(Instance::GetGameManager()->GetMoney()), 128.f, -224.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

	Input();
	if (isWarningOn == true)
	{
		warningDelay += dt;
		text.DrawTextWithColor("NOT ENOUGH MONEY", -112.f, 0.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		if (warningDelay > 12.f)
		{
			warningDelay = 0.f;
			isWarningOn = false;
		}
	}
}

void Shop::Restart()
{
}

void Shop::End()
{
	Instance::GetGameManager()->SetIsPlayerCanControl(true);
	delete player;
	player = nullptr;
}

void Shop::Input()
{
	switch (shopState)
	{
	case ShopState::MAIN:
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
		}
		else if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
		{
			if (selectionIndex < 2)
			{
				++selectionIndex;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1))
		{
			switch (selectionIndex)
			{
			case 0:
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::LASER);
				player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(100.f);
				selectionIndex = 0;
				shopState = ShopState::WEAPON;
				break;
			case 1:
				selectionIndex = 0;
				shopState = ShopState::EQUIPEMENT;
				break;
			case 2:
				Instance::GetLevelManager()->ChangeLevel(LevelType::STAGEDEMO);
				break;
			case 3:
				selectionIndex = 0;
				break;
			}
		}
		break;
	case ShopState::WEAPON:
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
			if (selectionIndex == 0)
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::LASER);
				player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(100.f);
			}
			else if (selectionIndex == 1)
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::HOMING);
				player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(80.f);
			}
			else
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::NORMAL);
			}
		}
		else if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
		{
			if (selectionIndex < 4)
			{
				++selectionIndex;
			}
			if (selectionIndex == 0)
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::LASER);
				player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(100.f);
			}
			else if (selectionIndex == 1)
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::HOMING);
				player->GetComponent<PlayerComponent>()->SetMaxSubShotDelay(80.f);
			}
			else
			{
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::NORMAL);
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1))
		{
			WeaponUpgrade();
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY3))
		{
			Instance::GetObjectManager()->DestroyAllObjects();
			Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::NORMAL);
			selectionIndex = 0;
			shopState = ShopState::MAIN;
		}
		break;
	case ShopState::EQUIPEMENT:
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().LEFT))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
		}
		else if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().RIGHT))
		{
			if (selectionIndex < 7)
			{
				++selectionIndex;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
		{
			if (selectionIndex >= 4 && selectionIndex < 8)
			{
				selectionIndex = selectionIndex - 4;
			}
		}
		else if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
		{
			if (selectionIndex >= 0 && selectionIndex < 4)
			{
				selectionIndex = selectionIndex + 4;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1))
		{
			EquipmentUpgrade();
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY3))
		{
			selectionIndex = 0;
			shopState = ShopState::MAIN;
		}
		break;
	}
}

void Shop::ShopMain()
{
	switch (selectionIndex)
	{
	case 0:
		text.DrawTextWithColor("WEAPON", -192.f, 128.f, 0.f, 2.0f, { 1.f, 0.f, 0.f, 1.f });
		text.DrawTextWithColor("EQUIP", -288.f, 32.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("SORTIE", -288.f, -64.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		text.DrawTextWithColor("WEAPON", -288.f, 128.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("EQUIP", -192.f, 32.f, 0.f, 2.0f, { 1.f, 0.f, 0.f, 1.f });
		text.DrawTextWithColor("SORTIE", -288.f, -64.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		text.DrawTextWithColor("WEAPON", -288.f, 128.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("EQUIP", -288.f, 32.f, 0.f, 2.0f, { 1.f, 1.f, 1.f, 1.f });
		text.DrawTextWithColor("SORTIE", -192.f, -64.f, 0.f, 2.0f, { 1.f, 0.f, 0.f, 1.f });
		break;
	}
}

void Shop::WeaponShop()
{
	switch (selectionIndex)
	{
	case 0:
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionLaser", { -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionHoming", { -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionExit", { -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("LASER", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionLaser", { -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionHoming", { -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionExit", { -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("HOMING", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionLaser", { -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionHoming", { -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionExit", { -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("NOT AVAILABLE \nIN THIS VERSION", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 3:
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionLaser", { -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionHoming", { -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionExit", { -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("NOT AVAILABLE \nIN THIS VERSION", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 4:
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionLaser", { -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionHoming", { -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionNone", { -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("WeaponSelectionExit", { -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,1.f,1.f,0.5f });

		text.DrawTextWithColor("EXIT", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	}
	player->GetComponent<PlayerComponent>()->Attack();
	player->GetComponent<PlayerComponent>()->SubAttack();
}

void Shop::EquipmentShop()
{
	switch (selectionIndex)
	{
	case 0:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("INCREASE MAX HP", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("EQUIP BARRIER WHICH BLOCK \nENEMY'S BULLET", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("NOT AVAILABLE IN THIS VERSION", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 3:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("NOT AVAILABLE IN THIS VERSION", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 4:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("NOT AVAILABLE IN THIS VERSION", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 5:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("NOT AVAILABLE IN THIS VERSION", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 6:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("NOT AVAILABLE IN THIS VERSION", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 7:
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionHP", { -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionBarrier", { -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		Instance::GetSpriteManager()->DrawSprite("EquipSelectionNone", { 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,1.f,1.f,0.5f });
		text.DrawTextWithColor("EXIT", 108.f, 30.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });

		text.DrawTextWithColor("EXIT", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	}
}

void Shop::WeaponUpgrade()
{
	switch (selectionIndex)
	{
	case 0:
		if (Instance::GetGameManager()->GetWeaponLevel().laser < 1)
		{
			if (Buy(100))
			{
				Instance::GetGameManager()->SetWeaponLevel(PlayerWeapon::LASER, 1);
			}
		}
		break;
	case 1:
		if (Instance::GetGameManager()->GetWeaponLevel().homing < 1)
		{
			if (Buy(100))
			{
				Instance::GetGameManager()->SetWeaponLevel(PlayerWeapon::HOMING, 1);
			}
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		Instance::GetObjectManager()->DestroyAllObjects();
		Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::NORMAL);
		selectionIndex = 0;
		shopState = ShopState::MAIN;
		break;
	}
}

void Shop::EquipmentUpgrade()
{
	switch (selectionIndex)
	{
	case 0:
		if (Buy(200))
		{
			Instance::GetGameManager()->SetMaxHp(Instance::GetGameManager()->GetMaxHp() + 10);
			Instance::GetGameManager()->AddHp(10);
		}
		break;
	case 1:
		if (Buy(500))
		{
			if (Instance::GetGameManager()->GetIsBarrier() != true)
			{
				Instance::GetGameManager()->SetIsBarrier(true);
			}
			else
			{

			}
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		selectionIndex = 0;
		shopState = ShopState::MAIN;
		break;
	}
}

bool Shop::Buy(int cost)
{
	if (Instance::GetGameManager()->GetMoney() >= cost)
	{
		Instance::GetGameManager()->SetMoney(Instance::GetGameManager()->GetMoney() - cost);
			return true;
		}
		else
		{
			isWarningOn = true;
			return false;
		}
	}
