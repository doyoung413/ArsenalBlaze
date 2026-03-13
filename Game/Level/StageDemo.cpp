#include "StageDemo.hpp"

#include "FileManager.hpp"
#include "Object/Item.hpp"
#include "Component/PlayerComponent.hpp"

void StageDemo::Init()
{
	FileManager::LoadLevelData("Game/Level/LevelData/LevelDemo.lvl");

	Instance::GetObjectManager()->FindObjectWithName("Player")->GetComponent<PlayerComponent>()->Init();
	Instance::GetGameManager()->SetScrollSpeed({ 0.f,-2.f });

	Instance::GetSpriteManager()->SetBackGroundColor({ 0.8f,0.8f,0.8f,1.f });
	if (Instance::GetGameManager()->GetGameMode() != GameMode::EDITOR)
	{
		Instance::GetObjectManager()->AddObject<Item>(0.f, 300.f, 4.f, 1.f, 32.f, 32.f, DrawType::SPRITE, "Item", ObjectType::ITEM);
		Instance::GetObjectManager()->AddObject<Item>(0.f, 2500.f, 4.f, 1.f, 32.f, 32.f, DrawType::SPRITE, "Item", ObjectType::ITEM);
		Instance::GetObjectManager()->AddObject<Item>(0.f, 4500.f, 4.f, 1.f, 32.f, 32.f, DrawType::SPRITE, "Item", ObjectType::ITEM);
	}
#ifdef _DEBUG
	mapEditor.Init();
#endif
}

void StageDemo::Update(float dt)
{
	Instance::GetGameManager()->Update(dt);
#ifdef _DEBUG
	mapEditor.Update();
#endif
}

void StageDemo::Restart()
{
	End();
	Init();
}

void StageDemo::End()
{
	Instance::GetCameraManager()->Reset();
	Instance::GetObjectManager()->DestroyAllObjects();
	Instance::GetBackgroundManager()->Clear();

#ifdef _DEBUG
	mapEditor.End();
#endif
}
