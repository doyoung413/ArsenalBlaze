#include "FileManager.hpp"
#include "Instance.hpp"

#include "Object/Player.hpp"
#include "Component/PlayerComponent.hpp"

#include <iostream>

void FileManager::LoadSetting(const std::filesystem::path& filePath)
{
	std::ifstream inStream;
	inStream.open(filePath);

	if (inStream.is_open() == false)
	{
		SaveSetting(filePath);
	}
	else
	{
		std::string value = "";
		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().UP = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().DOWN = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().LEFT = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().RIGHT = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().KEY1 = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().KEY2 = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().KEY3 = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		Instance::GetGameManager()->GetKeySetting().START = Instance::GetInputManager()->KeyBoardToEnum(value);

		inStream >> value;
		if (value == "FULLSCREEN:ON")
		{
			Instance::GetWindow()->ToggleFullScreen();
		}
	}
	inStream.close();
}

void FileManager::SaveSetting(const std::filesystem::path& outFilePath)
{
	std::ofstream saveLoad(outFilePath);

	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().UP) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().DOWN) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().LEFT) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().RIGHT) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().KEY1) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().KEY2) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().KEY3) << ' ';
	saveLoad << Instance::GetInputManager()->KeyBoardToString(Instance::GetGameManager()->GetKeySetting().START) << ' ';

	saveLoad << "\n";

	if (Instance::GetWindow()->IsFullscreen() == true)
	{
		saveLoad << "FULLSCREEN:ON" << "\n";
	}
	else
	{
		saveLoad << "FULLSCREEN:OFF" << "\n";
	}
	saveLoad.close();
}
