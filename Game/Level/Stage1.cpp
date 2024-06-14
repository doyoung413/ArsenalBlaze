#include "Stage1.hpp"

#include "FileManager.hpp"
#include "Component/PlayerComponent.hpp"

void Stage1::Init()
{
	FileManager::LoadLevelData("Game/Level/LevelData/Level1.lvl");

	gameManager = Instance::GetGameManager();
	objectManager = Instance::GetObjectManager();
	cameraManager = Instance::GetCameraManager();
	backgroundManager = Instance::GetBackgroundManager();
	soundManager = Instance::GetSoundManager();
	cameraManager->SetZoom(0.9f);

	objectManager->FindObjectWithName("Player")->GetComponent<PlayerComponent>()->Init();
#ifdef _DEBUG
	mapEditor.Init();
#endif
}

void Stage1::Update(float dt)
{
	gameManager->DrawUI(dt);
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
