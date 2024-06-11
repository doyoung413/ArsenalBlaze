#include "Option.hpp"
#include "FileManager.hpp"

#include <iostream>

void Option::KeyChanging(int index_, float dt)
{
	if (isKeySetting == true && isSelected == false)
	{
		switch (index)
		{
		case 0:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 1:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 2:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 3:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 4:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 5:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 6:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			break;
		case 7:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			break;
		}


		text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nPRESS R TO RESET KEY SET", -144.f, 300.f, 0.f, 1.0f, 1.f);
		if (inputManager->IsKeyPressOnce(KEYBOARDKEYS::R))
		{
			gameManager->GetKeySetting().UP = KEYBOARDKEYS::UP;
			gameManager->GetKeySetting().DOWN = KEYBOARDKEYS::DOWN;
			gameManager->GetKeySetting().LEFT = KEYBOARDKEYS::LEFT;
			gameManager->GetKeySetting().RIGHT = KEYBOARDKEYS::RIGHT;
			gameManager->GetKeySetting().KEY1 = KEYBOARDKEYS::Z;
			gameManager->GetKeySetting().KEY2 = KEYBOARDKEYS::X;
			gameManager->GetKeySetting().KEY3 = KEYBOARDKEYS::C;
			gameManager->GetKeySetting().START = KEYBOARDKEYS::ENTER;
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY2) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_KEY2))
		{
			index = 0;
			isKeySetting = false;
		}
	}

	if (isKeySetting == true && isSelected == true)
	{
		changeDelay += 0.1f * dt;
		switch (index_)
		{
		case 0:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().UP = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 1:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().DOWN = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 2:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().LEFT = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 3:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().RIGHT = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 4:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().KEY1 = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 5:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().KEY2 = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 6:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().KEY3 = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 7:
			text.DrawTextWithColor("\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (inputManager->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					gameManager->GetKeySetting().START = inputManager->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		}
	}
}

void Option::Input()
{
	if (isKeySetting == false)
	{
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().UP) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_UP))
		{
			if (index > 0)
			{
				index--;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().DOWN) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_DOWN))
		{
			if (index < 3)
			{
				index++;
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY1) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_KEY1) ||
			inputManager->IsKeyPressOnce(gameManager->GetKeySetting().START) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_START))
		{
			switch (index)
			{
			case 0:
				isSelected = true;
				break;
			case 1:
				break;
			case 2:
				Instance::GetWindow()->ToggleFullScreen();
				break;
			case 3:
				isSelected = true;
				break;
			}
		}
	}
	else
	{
		if (isSelected == false)
		{
			if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().UP) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_UP))
			{
				if (index > 0)
				{
					index--;
				}
			}
			if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().DOWN) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_DOWN))
			{
				if (index < 7)
				{
					index++;
				}
			}
		}
		if (inputManager->IsKeyPressOnce(gameManager->GetKeySetting().KEY1) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_KEY1) ||
			inputManager->IsKeyPressOnce(gameManager->GetKeySetting().START) || inputManager->IsGamepadButtonPressOnce(gameManager->GetKeySetting().PAD_START))
		{
			if (isSelected == false)
			{
				isSelected = true;
			}
		}
	}
}

void Option::Init()
{
	gameManager = Instance::GetGameManager();
	spriteManager = Instance::GetSpriteManager();
	inputManager = Instance::GetInputManager();

	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(spriteManager->GetShader());
	isSelected = false;
	index = 0;
}

void Option::Update(float dt)
{
	{
		text.DrawTextWithColor("OPTION", -72.f, 300.f, 0.f, 1.0f, 1.f);
		KeyChanging(index, dt);

		if (isKeySetting == false)
		{
			switch (index)
			{
			case 0:
				text.DrawTextWithColor("\n\nKEY SETTING", -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n        KEYMODE: A\n(KEY1:MAIN+SUB KEY2:SPECIAL) ", -200.f, 300.f, 0.f, 1.0f, 1.f); //¹Ù²Ü°Å - °ø¶õ

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : ON", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : OFF", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBACK TO TITLE", -72.f, 300.f, 0.f, 1.0f, 1.f);

				break;
			case 1:
				text.DrawTextWithColor("\n\nKEY SETTING", -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n        KEYMODE: A\n(KEY1:MAIN+SUB KEY2:SPECIAL) ", -200.f, 300.f, 0.f, 1.0f, 1.f); //¹Ù²Ü°Å - °ø¶õ

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : ON", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : OFF", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBACK TO TITLE", -72.f, 300.f, 0.f, 1.0f, 1.f);
				break;
			case 2:
				text.DrawTextWithColor("\n\nKEY SETTING", -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n        KEYMODE: A\n(KEY1:MAIN+SUB KEY2:SPECIAL) ", -200.f, 300.f, 0.f, 1.0f, 1.f); //¹Ù²Ü°Å - °ø¶õ

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : ON", -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : OFF", -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				}

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBACK TO TITLE", -72.f, 300.f, 0.f, 1.0f, 1.f);
				break;
			case 3:
				text.DrawTextWithColor("\n\nKEY SETTING", -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nKEY3:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY3)), -72.f, 300.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 300.f, 0.f, 1.0f, 1.f);

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n        KEYMODE: A\n(KEY1:MAIN+SUB KEY2:SPECIAL) ", -200.f, 300.f, 0.f, 1.0f, 1.f); //¹Ù²Ü°Å - °ø¶õ

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : ON", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nFULL SCREEN : OFF", -72.f, 300.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBACK TO TITLE", -72.f, 300.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				break;
			}
		}

		else if (isSelected == true && isKeySetting == false)
		{
			switch (index)
			{
			case 0:
				isSelected = false;
				isKeySetting = true;
				break;
			case 3:
				FileManager::SaveSetting("../Setting.ini");
				break;
			}
		}
	}
}

void Option::Restart()
{
	End();
	Init();
}

void Option::End()
{
	gameManager = nullptr;
	spriteManager = nullptr; 
	inputManager = nullptr;
}
