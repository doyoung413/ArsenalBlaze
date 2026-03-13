#include "Option.hpp"
#include "FileManager.hpp"

#include <iostream>

void Option::MainOptionMenu()
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
		text.DrawTextWithColor("\n\n\n\n\n\nVOLUME : " + std::to_string(static_cast<int>(std::round(Instance::GetSoundManager()->GetChannelVolume(1) * 100))), -144.f, 208.f, 0.f, 1.0f, 1.f);
		{
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSOUND : " + std::to_string(soundIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

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
		text.DrawTextWithColor("\n\n\n\n\n\nVOLUME : " + std::to_string(static_cast<int>(std::round(Instance::GetSoundManager()->GetChannelVolume(1) * 100))), -144.f, 208.f, 0.f, 1.0f, 1.f);
		{
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSOUND : " + std::to_string(soundIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

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
		text.DrawTextWithColor("\n\n\n\n\n\nVOLUME : " + std::to_string(static_cast<int>(std::round(Instance::GetSoundManager()->GetChannelVolume(1) * 100))), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
		{
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSOUND : " + std::to_string(soundIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

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
		text.DrawTextWithColor("\n\n\n\n\n\nVOLUME : " + std::to_string(static_cast<int>(std::round(Instance::GetSoundManager()->GetChannelVolume(1) * 100))), -144.f, 208.f, 0.f, 1.0f, 1.f);
		{
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSOUND : " + std::to_string(soundIndex), -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

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
		text.DrawTextWithColor("\n\n\n\n\n\nVOLUME : " + std::to_string(static_cast<int>(std::round(Instance::GetSoundManager()->GetChannelVolume(1) * 100))), -144.f, 208.f, 0.f, 1.0f, 1.f);
		{
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\nSOUND TEST ", -144.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\nSOUND : " + std::to_string(soundIndex), -144.f, 208.f, 0.f, 1.0f, 1.f);

		}
		text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nRETURN TO TITLE", -144.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });

		break;
	}
}

void Option::KeyChanging(int index_, float dt)
{
	if (isKeySetting == true && isSelected == false)
	{
		switch (index)
		{
		case 0:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 1:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 2:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 3:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 4:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 5:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 6:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, 1.f);
			break;
		case 7:
			text.DrawTextWithColor("\n\n\nUP:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\nDOWN:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\nLEFT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\nRIGHT:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\nKEY1:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\nKEY2:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -72.f, 208.f, 0.f, 1.0f, 1.f);
			text.DrawTextWithColor("\n\n\n\n\n\n\n\n\nSTART:" + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -72.f, 208.f, 0.f, 1.0f);
			text.DrawTextWithColor(("\n\n\n\n\n\n\n\n\n\n\nRETURN TO MENU"), -72.f, 208.f, 0.f, 1.0f, { 1.f, 0.f, 0.f, 1.f });
			break;
		}

		text.DrawTextWithColor("\n\n\n\n\n\n\n\n\n\n\n\n\n\nPRESS R TO RESET KEY SET", -176.f, 208.f, 0.f, 1.0f, 1.f);
		if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::R))
		{
			Instance::GetGameManager()->ResetKeySetting();
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY2) || Instance::GetInputManager()->IsGamepadButtonPressOnce(Instance::GetGameManager()->GetKeySetting().PAD_KEY2))
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
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().UP)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().UP = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 1:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().DOWN)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().DOWN = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 2:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().LEFT)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().LEFT = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 3:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().RIGHT)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().RIGHT = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 4:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY1)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().KEY1 = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 5:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().KEY2)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().KEY2 = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 6:
			text.DrawTextWithColor("\n\n\n\n\n\nPRESS KEY TO CHANGE: " + Instance::GetInputManager()->KeyBoardToString((Instance::GetGameManager()->GetKeySetting().START)), -144.f, 208.f, 0.f, 1.0f, 1.f);
			if (changeDelay > 1.f)
			{
				if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
				{
					Instance::GetGameManager()->GetKeySetting().START = Instance::GetInputManager()->GetPressKey();
					isSelected = false;
					changeDelay = 0.f;
				}
			}
			break;
		case 7:
			index = 0;
			isKeySetting = false;
			break;
		}
	}
}

void Option::Input()
{
	if (isKeySetting == false)
	{
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
		{
			if (index > 0)
			{
				index--;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
		{
			if (index < 4)
			{
				index++;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1))
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
			case 3:
				Instance::GetSoundManager()->Play(soundIndex, 1);
				break;
			case 4:
				FileManager::SaveSetting("Setting.ini");
				Instance::GetLevelManager()->ChangeLevel(LevelType::TITLE);
				break;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().LEFT))
		{
			switch (index)
			{
			case 2:
				Instance::GetSoundManager()->VolumeDown();
				break;
			case 3:
				if (soundIndex > 0)
				{
					soundIndex--;
				}
				else
				{
					soundIndex = Instance::GetSoundManager()->GetAmontOfSounds() - 1;
				}
				break;
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().RIGHT))
		{
			switch (index)
			{
			case 2:
				Instance::GetSoundManager()->VolumeUp();
				break;
			case 3:
				if (soundIndex < Instance::GetSoundManager()->GetAmontOfSounds() - 1)
				{
					soundIndex++;
				}
				else
				{
					soundIndex = 0;
				}
				break;
			}
		}
	}
	else
	{
		if (isSelected == false)
		{
			if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().UP))
			{
				if (index > 0)
				{
					index--;
				}
			}
			if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().DOWN))
			{
				if (index < 7)
				{
					index++;
				}
			}
		}
		if (Instance::GetInputManager()->IsKeyPressOnce(Instance::GetGameManager()->GetKeySetting().KEY1))
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
	text.LoadFromFile("Assets/font.fnt");
	text.SetShader(Instance::GetSpriteManager()->GetShader());
	index = 0;
}

void Option::Update(float dt)
{
	{
		text.DrawTextWithColor("OPTION", -48.f, 208.f, 0.f, 1.0f, 1.f);

		KeyChanging(index, dt);
		if (isKeySetting == false)
		{
			MainOptionMenu();
		}

		else if (isSelected == true && isKeySetting == false)
		{
			switch (index)
			{
			case 0:
				isSelected = false;
				isKeySetting = true;
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
}
