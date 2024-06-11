#include "Shop.hpp"

#include <string>

void Shop::Init()
{
	spriteManager = Instance::GetSpriteManager();
	gameManager = Instance::GetGameManager();
	objectManager = Instance::GetObjectManager();
	soundManager = Instance::GetSoundManager();
	inputManager = Instance::GetInputManager();

	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(spriteManager->GetShader());
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
		break;
	case ShopState::EQUIPEMENT:
		EquipmentShop();
		break;
	}
	text.DrawTextWithColor("MONEY " + std::to_string(gameManager->GetMoney()), 176.f, -224.f, 0.f, 1.0f, {1.f, 1.f, 1.f, 1.f});
	
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
	spriteManager = nullptr;
	gameManager = nullptr;
	objectManager = nullptr;
	soundManager = nullptr;
	inputManager = nullptr;
}

void Shop::Input()
{
	switch (shopState)
	{
	case ShopState::MAIN:
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().UP))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
		}
		else if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().DOWN))
		{
			if (selectionIndex < 3)
			{
				++selectionIndex;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY1))
		{
			switch (selectionIndex)
			{
			case 0:
				selectionIndex = 0;
				shopState = ShopState::WEAPON;
				break;
			case 1:
				selectionIndex = 0;
				shopState = ShopState::EQUIPEMENT;
				break;
			case 2:
				selectionIndex = 0;
				break;
			case 3:
				selectionIndex = 0;
				break;
			}
		}
		break;
	case ShopState::WEAPON:
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().UP))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
		}
		else if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().DOWN))
		{
			if (selectionIndex < 4)
			{
				++selectionIndex;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY1))
		{
			WeaponUpgrade();
		}
		break;
	case ShopState::EQUIPEMENT:
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().LEFT))
		{
			if (selectionIndex > 0)
			{
				--selectionIndex;
			}
		}
		else if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().RIGHT))
		{
			if (selectionIndex < 7)
			{
				++selectionIndex;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().UP))
		{
			if (selectionIndex >= 4 && selectionIndex < 8)
			{
				selectionIndex = selectionIndex - 4;
			}
		}
		else if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().DOWN))
		{
			if (selectionIndex >= 0 && selectionIndex < 4)
			{
				selectionIndex = selectionIndex + 4;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY1))
		{
			EquipmentUpgrade();
		}
		break;
	}
}

void Shop::ShopMain()
{
	switch (selectionIndex)
	{
	case 0:
		spriteManager->DrawRectangle({ -192.f, 128.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, 32.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, -64.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -256.f, -216.f, 0.f }, 0.f, { 48.f, 24.f, 0.f });
		break;
	case 1:
		spriteManager->DrawRectangle({ -224.f, 128.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -192.f, 32.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, -64.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -256.f, -216.f, 0.f }, 0.f, { 48.f, 24.f, 0.f });
		break;
	case 2:
		spriteManager->DrawRectangle({ -224.f, 128.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, 32.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -192.f, -64.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -256.f, -216.f, 0.f }, 0.f, { 48.f, 24.f, 0.f });
		break;
	case 3:
		spriteManager->DrawRectangle({ -224.f, 128.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, 32.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -224.f, -64.f, 0.f }, 0.f, { 96.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -256.f, -216.f, 0.f }, 0.f, { 48.f, 24.f, 0.f });
		break;
	}
}

void Shop::WeaponShop()
{
	switch (selectionIndex)
	{
	case 0:
		spriteManager->DrawRectangle({ -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, {1.f,0.f,0.f,1.f});
		spriteManager->DrawRectangle({ -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("UP:", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		spriteManager->DrawRectangle({ -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("UP:", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		spriteManager->DrawRectangle({ -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("UP:", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 3:
		spriteManager->DrawRectangle({ -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });

		text.DrawTextWithColor("UP:", -100.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 4:
		spriteManager->DrawRectangle({ -176.f, 176.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 96.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, 16.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -66.f, 0.f }, 0.f, { 32.f, 32.f, 0.f });
		spriteManager->DrawRectangle({ -176.f, -146.f, 0.f }, 0.f, { 32.f, 32.f, 0.f }, { 1.f,0.f,0.f,1.f });
		break;
	}
}

void Shop::EquipmentShop()
{
	switch (selectionIndex)
	{
	case 0:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 1:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 2:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 3:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 4:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 5:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 6:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	case 7:
		spriteManager->DrawRectangle({ -144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 126.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ -48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 48.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f });
		spriteManager->DrawRectangle({ 144.f, 30.f, 0.f }, 0.f, { 48.f, 48.f, 0.f }, { 1.f,0.f,0.f,1.f });

		text.DrawTextWithColor("UP:", -176.f, -66.f, 0.f, 1.0f, { 1.f, 1.f, 1.f, 1.f });
		break;
	}
}

void Shop::WeaponUpgrade()
{
	switch (selectionIndex)
	{
	case 0:
		if (Buy(100))
		{

		}
		break;
	case 1:
		if (Buy(100))
		{

		}
		break;
	case 2:
		if (Buy(100))
		{

		}
		break;
	case 3:
		if (Buy(100))
		{

		}
		break;
	case 4:
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
		if (Buy(100))
		{

		}
		break;
	case 1:
		if (Buy(100))
		{

		}
		break;
	case 2:
		if (Buy(100))
		{

		}
		break;
	case 3:
		if (Buy(100))
		{

		}
		break;
	case 4:
		if (Buy(100))
		{

		}
		break;
	case 5:
		if (Buy(100))
		{

		}
		break;
	case 6:
		if (Buy(100))
		{

		}
		break;
	case 7:
		selectionIndex = 0;
		shopState = ShopState::MAIN;
		break;
	}
}

bool Shop::Buy(int cost)
{
	if (gameManager->GetMoney() >= cost)
	{
		gameManager->SetMoney(gameManager->GetMoney() - cost);
		return true;
	}
	else
	{
		isWarningOn = true;
		return false;
	}
}
