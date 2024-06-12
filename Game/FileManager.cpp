#include "FileManager.hpp"
#include "Instance.hpp"

#include "Object/Player.hpp"
#include "Object/Enemy.hpp"
#include "Component/PlayerComponent.hpp"

#include "Object/Enemy.hpp"
#include "Object/EnemyToward.hpp"
#include "Object/EnemyTowardA.hpp"
#include "Object/EnemyMoveS.hpp"
#include "Object/EnemyMoveU.hpp"
#include "Object/EnemySideAppear.hpp"
#include "Object/EnemyRobotA.hpp"
#include "Object/EnemyBigA.hpp"

#include <iostream>

EnemyType CharEnemyTypeToEnum(std::string kind)
{
	if (kind == "TOWARD")
		return EnemyType::TOWARD;
	else if (kind == "TOAWRD_A")
		return EnemyType::TOAWRD_A;
	else if (kind == "MOVE_S")
		return EnemyType::MOVE_S;
	else if (kind == "MOVE_U")
		return EnemyType::MOVE_U;
	else if (kind == "ROBOT_A")
		return EnemyType::ROBOT_A;
	else if (kind == "BIG_A")
		return EnemyType::BIG_A;
	else if (kind == "SIDE_APPEAR")
		return EnemyType::SIDE_APPEAR;
	else if (kind == "NONE")
		return EnemyType::NONE;

	return EnemyType::NONE;
}

const char* EnemyTypeEnumToChar(EnemyType type)
{
	switch (type)
	{
	case EnemyType::TOWARD:
		return "TOWARD";
		break;
	case EnemyType::TOAWRD_A:
		return "TOWARD";
		break;
	case EnemyType::MOVE_S:
		return "MOVE_S";
		break;
	case EnemyType::MOVE_U:
		return "MOVE_U";
		break;
	case EnemyType::ROBOT_A:
		return "ROBOT_A";
		break;
	case EnemyType::BIG_A:
		return "BIG_A";
		break;
	case EnemyType::SIDE_APPEAR:
		return "SIDE_APPEAR";
		break;
	case EnemyType::NONE:
		return "NONE";
		break;
	}
	return "NONE";
}

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


void FileManager::LoadLevelData(const std::filesystem::path& filePath)
{

	std::ifstream inStream;
	inStream.open(filePath);

	if (inStream.is_open() == false)
	{
		std::cout << "Fail to Access file";
	}

	while (!inStream.eof()) //Loop continue until .txt file end
	{
		float posX;
		float posY;
		float sizeX;
		float sizeY;
		float speedX;
		float speedY;
		float angle;
		float depth;

		std::string objectName;
		std::string drawType;
		std::string spriteName;
		std::string objectType = "";

		DrawType dType = DrawType::NONE;

		inStream >> objectName;
		inStream >> posX;
		inStream >> posY;
		inStream >> speedX;
		inStream >> speedY;
		inStream >> sizeX;
		inStream >> sizeY;
		inStream >> angle;
		inStream >> depth;
		inStream >> objectType;
		inStream >> drawType;
		inStream >> spriteName;

		if (drawType == "NONE")
		{
			dType = DrawType::NONE;
		}
		else if (drawType == "RECTANGLE")
		{
			dType = DrawType::RECTANGLE;
		}
		else if (drawType == "RECTANGLELINE")
		{
			dType = DrawType::RECTANGLELINE;
		}
		else if (drawType == "SPRITE")
		{
			dType = DrawType::SPRITE;
		}
		else if (drawType == "SPRITEANIMATION")
		{
			dType = DrawType::SPRITEANIMATION;
		}

		if (objectType == "PLAYER")
		{
			Instance::GetObjectManager()->AddObject<Player>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, ObjectType::PLAYER);
			Instance::GetObjectManager()->GetLastObject()->SetRotate(angle);
			Instance::GetObjectManager()->GetLastObject()->SetSpriteName(spriteName);
			Instance::GetObjectManager()->GetLastObject()->SetDepth(depth);
		}
		else if (objectType == "ENEMY")
		{
			float spawnPosOffX;
			float spawnPosOffY;
			float stopPosOffX;
			float stopPosOffY;
			int reverse;
			std::string enemyType;

			inStream >> spawnPosOffX;
			inStream >> spawnPosOffY;
			inStream >> stopPosOffX;
			inStream >> stopPosOffY;
			inStream >> reverse;
			inStream >> enemyType;

			switch (CharEnemyTypeToEnum(enemyType))
			{
			case EnemyType::TOWARD:
				Instance::GetObjectManager()->AddObject<EnemyToward>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::TOAWRD_A:
				Instance::GetObjectManager()->AddObject<EnemyTowardA>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::MOVE_S:
				Instance::GetObjectManager()->AddObject<EnemyMoveS>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::MOVE_U:
				Instance::GetObjectManager()->AddObject<EnemyMoveU>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::SIDE_APPEAR:
				Instance::GetObjectManager()->AddObject<EnemySideAppear>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::ROBOT_A:
				Instance::GetObjectManager()->AddObject<EnemyRobotA>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			case EnemyType::BIG_A:
				Instance::GetObjectManager()->AddObject<EnemyBigA>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, glm::vec2{ spawnPosOffX, spawnPosOffY }, glm::vec2{ stopPosOffX, stopPosOffY });
				break;
			}
			Instance::GetObjectManager()->GetLastObject()->SetRotate(angle);
			Instance::GetObjectManager()->GetLastObject()->SetSpriteName(spriteName);
			Instance::GetObjectManager()->GetLastObject()->SetDepth(depth);

			if (reverse == 1)
			{
				static_cast<EnemyMoveS*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(true);
			}
			else
			{
				static_cast<EnemyMoveS*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(false);
			}

		}
		else if (objectType == "NONE")
		{
			Instance::GetObjectManager()->AddObject<Object>(posX, posY, speedX, speedY, sizeX, sizeY, dType, objectName, ObjectType::PLAYER);
			Instance::GetObjectManager()->GetLastObject()->SetSpriteName(spriteName);
			Instance::GetObjectManager()->GetLastObject()->SetDepth(depth);
		}

		else if (objectType == "BACKGROUND")
		{
			std::string bType;
			bool isScrolled;
			inStream >> bType;
			inStream >> isScrolled;
			if (bType == "NORMAL")
			{
				Instance::GetBackgroundManager()->AddNormalBackground(spriteName, { posX, posY }, { sizeX, sizeY }, angle, { speedX, speedY }, { 0.f,0.f }, depth, isScrolled);
			}
			else if (bType == "TILE")
			{
				Instance::GetBackgroundManager()->AddTileBackground(spriteName, objectName, { posX, posY }, { sizeX, sizeY }, { speedX, speedY }, depth, isScrolled);
			}
			else if (bType == "VPARALLEX")
			{
				Instance::GetBackgroundManager()->AddVerticalParallexBackground(spriteName, objectName, { posX, posY }, { sizeX, sizeY }, angle, speedY, depth, isScrolled);
			}
		}
	}
	inStream.close();
}

void FileManager::SaveLevelData(const std::filesystem::path& outFilePath)
{
	std::ofstream saveLoad(outFilePath);

	for (auto& target : Instance::GetObjectManager()->GetObjectMap())
	{
		saveLoad << target.second.get()->GetName() << ' ';
		saveLoad << target.second.get()->GetPosition().x << ' ';
		saveLoad << target.second.get()->GetPosition().y << ' ';
		saveLoad << target.second.get()->GetSpeed().x << ' ';
		saveLoad << target.second.get()->GetSpeed().y << ' ';
		saveLoad << target.second.get()->GetSize().x << ' ';
		saveLoad << target.second.get()->GetSize().y << ' ';
		saveLoad << target.second.get()->GetRotate() << ' ';
		saveLoad << target.second.get()->GetDepth() << ' ';


		if (target.second.get()->GetObjectType() == ObjectType::PLAYER)
		{
			saveLoad << "PLAYER" << ' ';
		}
		else if (target.second.get()->GetObjectType() == ObjectType::ENEMY)
		{
			saveLoad << "ENEMY" << ' ';
		}
		else if (target.second.get()->GetObjectType() == ObjectType::NONE)
		{
			saveLoad << "NONE" << ' ';
		}


		if (target.second.get()->GetDrawType() == DrawType::NONE)
		{
			saveLoad << "NONE" << ' ';
			saveLoad << "none" << ' ';
		}
		else if (target.second.get()->GetDrawType() == DrawType::RECTANGLE)
		{
			saveLoad << "RECTANGLE" << ' ';
			saveLoad << "none" << ' ';
		}
		else if (target.second.get()->GetDrawType() == DrawType::RECTANGLELINE)
		{
			saveLoad << "RECTANGLELINE" << ' ';
			saveLoad << "none" << ' ';
		}
		else if (target.second.get()->GetDrawType() == DrawType::SPRITE)
		{
			saveLoad << "SPRITE" << ' ';
			saveLoad << target.second.get()->GetSpriteName() << ' ';
		}
		else if (target.second.get()->GetDrawType() == DrawType::SPRITEANIMATION)
		{
			saveLoad << "SPRITEANIMATION" << ' ';
			saveLoad << target.second.get()->GetSpriteName() << ' ';
		}

		if (target.second.get()->GetObjectType() == ObjectType::ENEMY)
		{
			saveLoad << static_cast<Enemy*>(target.second.get())->GetSpawnPositionOffset().x << ' ';
			saveLoad << static_cast<Enemy*>(target.second.get())->GetSpawnPositionOffset().y << ' ';
			saveLoad << static_cast<Enemy*>(target.second.get())->GetStopPositionOffset().x << ' ';
			saveLoad << static_cast<Enemy*>(target.second.get())->GetStopPositionOffset().x << ' ';
			if (static_cast<Enemy*>(target.second.get())->GetReverse() == 1.f)
			{
				saveLoad << 1 << ' ';
			}
			else
			{
				saveLoad << 0 << ' ';
			}
			saveLoad << EnemyTypeEnumToChar(static_cast<Enemy*>(target.second.get())->GetEnemyType()) << ' ';
		}
		saveLoad << '\n';
	}
	for (auto& group : Instance::GetBackgroundManager()->GetSaveBackgroundList())
	{
		for (auto& background : group.second)
		{
			saveLoad << group.first << ' ';
			saveLoad << background.position.x << ' ';
			saveLoad << background.position.y << ' ';
			saveLoad << background.speed.x << ' ';
			saveLoad << background.speed.y << ' ';
			saveLoad << background.size.x << ' ';
			saveLoad << background.size.y << ' ';
			saveLoad << background.angle << ' ';
			saveLoad << background.depth << ' ';
			saveLoad << "BACKGROUND" << ' ';
			saveLoad << "SPRITE" << ' ';
			saveLoad << background.spriteName << ' ';

			switch (background.type)
			{
			case BackgroundType::NORMAL:
				saveLoad << "NORMAL" << ' ';
				saveLoad << background.isScrolled;
				break;
			case BackgroundType::TILE:
				saveLoad << "TILE" << ' ';
				saveLoad << background.isScrolled;
				break;
			case BackgroundType::VPARALLEX:
				saveLoad << "VPARALLEX" << ' ';
				saveLoad << background.isScrolled;
				break;
			}
			saveLoad << '\n';
		}
	}

	saveLoad.close();
}
