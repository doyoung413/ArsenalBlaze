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
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 1:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 2:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 3:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 4:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 5:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 6:
			text.DrawTextWithColor("\n\n\nUP:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			break;
		}


		text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nPRESS R TO RESET KEY SET", -176.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().UP)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().DOWN)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().LEFT)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().RIGHT)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY1)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().KEY2)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + inputManager->KeyBoardToString((gameManager->GetKeySetting().START)), -144.f, 208.f, 0.f, 1.0f, 1.f);
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
			if (index < 6)
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
				isSelected = false;
				isKeySetting = true;
				break;
			case 1:
				Instance::GetWindow()->ToggleFullScreen();
				break;
			case 2:
				break;
			case 6:
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
				if (index < 6)
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
	soundManager = Instance::GetSoundManager();

	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(spriteManager->GetShader());
	index = 0;
}

void Option::Update(float dt)
{
	{
		text.DrawTextWithColor("OPTION", -48.f, 208.f, 0.f, 1.0f, 1.f);
		
		KeyChanging(index, dt);
		if (isKeySetting == false)
		{
			switch (index)
			{
			case 0:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 1:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 2:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 3:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 4:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 5:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, 1.f);

				break;
			case 6:
				text.DrawTextWithColor("\n\n\nKEY CONFIGURATION", -144.f, 208.f, 0.f, 1.0f);

				if (Instance::GetWindow()->IsFullscreen() == true)
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : ON", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}
				else
				{
					text.DrawTextWithColor("\n\n\n\nFULL SCREEN : OFF", -144.f, 208.f, 0.f, 1.0f, 1.f);
				}

				text.DrawTextWithColor("\n\n\n\n\nBGM VOLUME : " + std::to_string(soundManager->GetChannelVolume(0)), -144.f, 208.f, 0.f, 1.0f, 1.f);
				text.DrawTextWithColor("\n\n\n\n\n\nSE VOLUME : " + std::to_string(soundManager->GetChannelVolume(1)), -144.f, 208.f, 0.f, 1.0f, 1.f);

				{
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\nBGM " + std::to_string(bgmIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);
					text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSE " + std::to_string(seIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

				}
				text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

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
			case 6:
				FileManager::SaveSetting("../Setting.ini");
				break;
			}
		}
		Input();
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
	soundManager = nullptr;
}
