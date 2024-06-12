#include "Stage1.hpp"

#include "FileManager.hpp"
#include "Object/Player.hpp"
#include "Object/Item.hpp"

void Stage1::Init()
{
	FileManager::LoadLevelData("Game/Level/LevelData/Level1.lvl");

	gameManager = Instance::GetGameManager();
	objectManager = Instance::GetObjectManager();
	cameraManager = Instance::GetCameraManager();
	backgroundManager = Instance::GetBackgroundManager();
	soundManager = Instance::GetSoundManager();
	cameraManager->SetZoom(0.9f);
	//objectManager->AddObject<Player>(0.f, -128.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "Player", ObjectType::PLAYER);

#ifdef _DEBUG
	mapEditor.Init();
#endif
}

void Stage1::Update(float /*dt*/)
{
#ifdef _DEBUG
	mapEditor.Update();
#endif
}

void Stage1::Restart()
{
	End();
	Init();
}

void Stage1::End()
{
	cameraManager->Reset();
	objectManager->DestroyAllObjects();
	backgroundManager->Clear();

	gameManager = nullptr;
	objectManager = nullptr;
	cameraManager = nullptr;
	backgroundManager = nullptr;
	soundManager = nullptr;

#ifdef _DEBUG
	mapEditor.End();
#endif
}
