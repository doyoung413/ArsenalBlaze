#ifdef _DEBUG
#include "MyImGui.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "../GameEngine/Engine/Input.hpp"
#include "../GameEngine/Engine/Locator.hpp"

#include "../GameEngine/Game/FileIO.hpp"
#include "../GameEngine/Game/GameState.hpp"
#include "../GameEngine/Game/Background.hpp"

#include <cmath>
#include <iostream>
#endif

InputHandler* inputTest = nullptr;

#ifdef _DEBUG

const char* BackgroundTypeEnumToChar(BackgroundType type)
{
	switch (type)
	{
	case BackgroundType::NORMAL:
		return "NORMAL";
		break;
	case BackgroundType::TILE:
		return "TILE";
		break;
	case BackgroundType::VPARALLEX:
		return "VPARALLEX";
		break;
	}
	return "NORMAL";
}

const char* ObjectTypeEnumToChar(ObjectType type)
{
	switch (type)
	{
	case ObjectType::NONE:
		return "NONE";
		break;
	case ObjectType::PLAYER:
		return "PLAYER";
		break;
	case ObjectType::ENEMYSPAWNER:
		return "ENEMYSPAWNER";
		break;
	}
	return "NONE";
}

const char* DrawTypeEnumToChar(DrawType type)
{
	switch (type)
	{
	case DrawType::NONE:
		return "NONE";
		break;
	case DrawType::RECTANGLE:
		return "RECTANGLE";
		break;
	case DrawType::RECTANGLELINE:
		return "RECTANGLELINE";
		break;
	case DrawType::SPRITE:
		return "SPRITE";
		break;
	case DrawType::SPRITEANIMATION:
		return "SPRITEANIMATION";
		break;
	}
	return "NONE";
}

EnemyKinds SetEnemyspawnerKindList(EnemyKinds kind)
{
	int enumNumber = kind;
	if (ImGui::BeginCombo("EnemySpawnKinds", EnemyKindEnumToChar(kind)))
	{
		for (int i = 0; i < EnemyKinds::LAST; i++)
		{
			if (ImGui::Selectable(EnemyKindEnumToChar(static_cast<EnemyKinds>(i)), i))
			{
				enumNumber = static_cast<EnemyKinds>(i);
			}
			if (kind == static_cast<EnemyKinds>(i))
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
	return static_cast<EnemyKinds>(enumNumber);
}
#endif

#ifdef _DEBUG
void MyImGui::Init(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 100");
	if (GameManagers::Instance().GetObjectManager()->GetObjectMap().empty() == false)
	{
		target = GameManagers::Instance().GetObjectManager()->GetObjectMap().begin()->second.get();
	}
	targetBackground = new Background();
	targetBackground->position = { 0.f,0.f };
	targetBackground->size = { 32.f,32.f };
	targetBackground->speed = { 0.f,0.f };
	targetBackground->sizeIncrements = { 0.f,0.f };
	targetBackground->angle = 0.f;
	targetBackground->depth = -1.f;
	targetBackground->type = BackgroundType::NORMAL;
	targetBackground->spriteName = "none";

	newObject = new Object();
	newObject->SetXPosition(0.f);
	newObject->SetYPosition(0.f);
	newObject->SetXSpeed(0.f);
	newObject->SetYSpeed(0.f);
	newObject->SetXSize(32.f);
	newObject->SetYSize(32.f);
	newObject->SetDepth(0.f);
	newObject->SetSpriteName("none");

	inputTest = GameManagers::Instance().GetInputHandler();
}
#endif

#ifdef _DEBUG
void MyImGui::Update()
{
	GameManagers::Instance().GetSpriteManager()->DrawRectangleLine({ 0.f, 0.f }, 0.f, { GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().x / 2.f, GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().y / 2.f }, { 0.5f,1.f,0.5f,1.f });
	if (inputTest->IsKeyPressed(KeyboardKey::M))
	{
		if (Game::Instance().GetGameState() != GameState::EDITOR)
		{
			GameManagers::Instance().GetStateManager()->RestartLevel();
			Game::Instance().SetGameState(GameState::EDITOR);
		}
		else
		{
			GameManagers::Instance().GetStateManager()->RestartLevel();
			Game::Instance().SetGameState(GameState::RUNNING);
		}
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Input");
	ImGui::Text("X:%f Y:%f", inputTest->GetMousePositionX(), inputTest->GetMousePositionY());

	float volume = GameManagers::Instance().GetSoundManager()->GetSystemVolume();
	ImGui::Text("Volume:%f", volume);
	if (ImGui::Button("Up"))
	{
		GameManagers::Instance().GetSoundManager()->VolumeUp();
	}
	ImGui::SameLine();
	if (ImGui::Button("Down"))
	{
		GameManagers::Instance().GetSoundManager()->VolumeDown();
	}
	if (ImGui::Button("Play")) //키 입력 함수
	{
		GameManagers::Instance().GetSoundManager()->PlaySound("music");
	}
	ImGui::SameLine();
	if (ImGui::Button("Stop")) //키 입력 함수
	{
		GameManagers::Instance().GetSoundManager()->StopSound("music");
	}
	ImGui::SameLine();
	if (ImGui::Button("Pause")) //키 입력 함수
	{
		GameManagers::Instance().GetSoundManager()->PauseSound("music", true);
	}
	ImGui::SameLine();
	if (ImGui::Button("Resume")) //키 입력 함수
	{
		GameManagers::Instance().GetSoundManager()->PauseSound("music", false);
	}
	if (ImGui::Button("VSync")) //키 입력 함수
	{
		GameManagers::Instance().GetPlatformWindow()->ToggleVSync();
	}
	if (ImGui::Button("GamePause")) //키 입력 함수
	{
		if (Game::Instance().GetGameState() == GameState::RUNNING)
		{
			Game::Instance().SetGameState(GameState::PAUSE);
		}
		else if (Game::Instance().GetGameState() == GameState::PAUSE)
		{
			Game::Instance().SetGameState(GameState::RUNNING);
		}
	}
	ImGui::InputFloat("IdleX", &Game::Instance().idleSize.x, 1.0f, Game::Instance().idleSize.x);
	ImGui::InputFloat("IdleY", &Game::Instance().idleSize.y, 1.0f, Game::Instance().idleSize.y);
	ImGui::End();

	if (Game::Instance().GetGameState() == GameState::EDITOR)
	{
		LevelEditor();
	}

	MouseInputEvent();
	if (editMode == EditorMode::OBJMODIFIER || editMode == EditorMode::OBJCREATOR)
	{
		ObjectList();
	}
	else if (editMode == EditorMode::BACKGCREATOR)
	{
		BackgroundList();
	}

	//rendering
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//rendering
}
#endif

#ifdef _DEBUG
void MyImGui::End()
{
	delete targetBackground;
	delete newObject;
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void MyImGui::ObjectList()
{
	ImGui::Begin("ObjectList");
	ImGui::BeginChild("Scrolling");
	for (auto& obj : GameManagers::Instance().GetObjectManager()->GetObjectMap())
	{
		if (Game::Instance().GetGameState() == GameState::EDITOR)
		{
			if (obj.second.get()->isCollideWithPoint({ inputTest->GetMousePositionX(), inputTest->GetMousePositionY() })
				&& inputTest->IsMouseButtonPressed(LEFT_BUTTON))
				if (targetIsClicked == false && target == obj.second.get())
				{
					targetIsClicked = true;
				}
				else if (targetIsClicked == false && target != obj.second.get())
				{
					target = obj.second.get();
					GameManagers::Instance().GetCameraManager()->TargetAt(target->GetPosition());
				}
		}
		if (ImGui::Selectable(obj.second->GetName().c_str(), &obj.second))
		{
			editMode = EditorMode::OBJMODIFIER;
			target = obj.second.get();
			GameManagers::Instance().GetCameraManager()->TargetAt(target->GetPosition());
			targetIsClicked = true;
		}
	}
	ImGui::EndChild();
	ImGui::End();
	if (Game::Instance().GetGameState() == GameState::EDITOR)
	{
		if (editMode == EditorMode::OBJMODIFIER)
		{
			ObjectModifier();
			GameManagers::Instance().GetSpriteManager()->DrawRectangleLine(target->GetPosition(), 0.f, target->GetSize(), { 1.0f, 0.0f, 0.0f, 1.f }, 1.f);
		}
		if (editMode == EditorMode::OBJCREATOR)
		{
			ObjectCreator();
		}
	}
}

void MyImGui::ObjectModifier()
{
	if (target != nullptr)
	{
		float  targetP[2] = { target->GetPosition().x, target->GetPosition().y };
		float  targetScale[2] = { target->GetSize().x, target->GetSize().y };
		float  targetSpeed[2] = { target->GetSpeed().x, target->GetSpeed().y };

		ImGui::Begin("ObjectModifier");
		SpriteList(target);
		DrawTypeList(target);
		ObjectTypeList(target);

		ImGui::Text("Collide Box Min:(%f, %f)\n Max:(%f, %f)", target->GetMin().x, target->GetMin().y, target->GetMax().x, target->GetMax().y);
		ImGui::InputFloat2("Position", targetP);
		target->SetXPosition(targetP[0]);
		target->SetYPosition(targetP[1]);

		ImGui::InputFloat2("Scale", targetScale);
		target->SetXSize(targetScale[0]);
		target->SetYSize(targetScale[1]);

		ImGui::InputFloat2("Speed", targetSpeed);
		target->SetXSpeed(targetSpeed[0]);
		target->SetYSpeed(targetSpeed[1]);

		float angle = target->GetRotate();
		ImGui::SliderFloat("Rotate", &angle, -360.0f, 360.0f);
		target->SetRotate(angle);

		Color4f color = target->GetColor();
		ImGui::ColorEdit4("clear color", (float*)&color);
		target->SetColor(color);

		switch (target->GetObjectType())
		{
		case ObjectType::ENEMYSPAWNER:
			ImGui::BeginChild("EnemySpawner");
			float  spawnDelayMax = static_cast<EnemySpawner*>(target)->GetSpawnDelayMax();
			float  spawnDelayIncreased = static_cast<EnemySpawner*>(target)->GetSpawnDelayIncreased();
			int  spawnAmountMax = static_cast<EnemySpawner*>(target)->GetSpawnAmountMax();

			ImGui::InputFloat("SpawnDelayMax", &spawnDelayMax, 0.1f, 256.f, "% .1f");
			ImGui::InputFloat("SpawnDelayIncreased", &spawnDelayIncreased, 0.1f, 256.f, "% .1f");
			ImGui::InputInt("SpawnAmountMax", &spawnAmountMax, 1, 256);

			static_cast<EnemySpawner*>(target)->SetSpawnDelayMax(spawnDelayMax);
			static_cast<EnemySpawner*>(target)->SetSpawnDelayIncreased(spawnDelayIncreased);
			static_cast<EnemySpawner*>(target)->SetSpawnAmountMax(spawnAmountMax);

			float offsetSpawnT[2] = { static_cast<EnemySpawner*>(target)->GetSpawnPositionOffset().x, static_cast<EnemySpawner*>(target)->GetSpawnPositionOffset().y};
			float offsetStopT[2] = { static_cast<EnemySpawner*>(target)->GetStopPositionOffSet().x, static_cast<EnemySpawner*>(target)->GetStopPositionOffSet().y };

			ImGui::InputFloat("offsetSpawnX", &offsetSpawnT[0], 1.0f, 256.f, "% 0.1f");
			ImGui::InputFloat("offsetStopX", &offsetStopT[0], 1.0f, 256.f, "% 0.1f");

			ImGui::InputFloat("offsetSpawnY", &offsetSpawnT[1], 1.0f, 256.f, "% 0.1f");
			ImGui::InputFloat("offsetStopY", &offsetStopT[1], 1.0f, 256.f, "% 0.1f");

			static_cast<EnemySpawner*>(target)->SetSpawnPositionOffset(offsetSpawnT[0], offsetSpawnT[1]);
			static_cast<EnemySpawner*>(target)->SetStopPositionOffSet(offsetStopT[0], offsetStopT[1]);

			bool reverseFlagT = static_cast<EnemySpawner*>(target)->GetIsReverse();
			ImGui::Checkbox("Reverse", &reverseFlagT);
			static_cast<EnemySpawner*>(target)->SetIsReverse(reverseFlagT);

			EnemyspawnerKindList(target);

			ImGui::EndChild();
			break;
		}
		ImGui::End();
	}
}

void MyImGui::ObjectCreator()
{
	float  targetP[2] = { newObject->GetPosition().x, newObject->GetPosition().y };
	float  targetScale[2] = { newObject->GetSize().x, newObject->GetSize().y };
	float  targetSpeed[2] = { newObject->GetSpeed().x, newObject->GetSpeed().y };
	float targetDepth = newObject->GetDepth();

	ImGui::Begin("ObjectCreator");
	SpriteList(newObject);
	DrawTypeList(newObject);
	ObjectTypeList(newObject);

	static char newName[256] = "none";
	ImGui::InputText("default", newName, 256);
	newObjectName = newName;

	ImGui::InputFloat2("Position", targetP);
	vec2<float> newPosition = { inputTest->GetMousePositionX() - std::fmod(inputTest->GetMousePositionX(), targetBackground->size.x),  inputTest->GetMousePositionY() - std::fmod(inputTest->GetMousePositionY(), targetBackground->size.y) };
	newObject->SetXPosition(newPosition.x);
	newObject->SetYPosition(newPosition.y);

	ImGui::InputFloat2("Scale", targetScale);
	vec2<float> newSize = { targetScale[0], targetScale[1] };
	newObject->SetXSize(newSize.x);
	newObject->SetYSize(newSize.y);

	ImGui::InputFloat2("Speed", targetSpeed);
	vec2<float> newSpeed = { targetSpeed[0], targetSpeed[1] };
	newObject->SetXSpeed(newSpeed.x);
	newObject->SetYSpeed(newSpeed.y);

	ImGui::InputFloat("Depth", &targetDepth, 0.1f, 1.0f);
	newObject->SetDepth(targetDepth);

	switch (newObject->GetObjectType())
	{
	case ObjectType::ENEMYSPAWNER:
		ImGui::BeginChild("EnemySpawner");
		ImGui::InputFloat("SpawnDelayMax", &spawnDelayMaxAmount, 0.1f, 256.f, "% .1f");
		ImGui::InputFloat("SpawnDelayIncreased", &spawnDelayIncreasedAmount, 0.1f, 256.f, "% .1f");
		ImGui::InputInt("SpawnAmountMax", &spawnAmountMaxAmount, 1, 256);

		static float  offsetSpawnT[2] = { offsetSpawn.x, offsetSpawn.y };
		static float  offsetStopT[2] = { offsetStop.x, offsetStop.y };
		ImGui::InputFloat2("offsetSpawn", offsetSpawnT);
		ImGui::InputFloat2("offsetStop", offsetStopT);
		static_cast<EnemySpawner*>(newObject)->SetSpawnPositionOffset(offsetSpawn.x, offsetSpawn.y);
		static_cast<EnemySpawner*>(newObject)->SetStopPositionOffSet(offsetStop.x, offsetStop.y);

		reverseFlag = static_cast<EnemySpawner*>(newObject)->GetIsReverse();
		ImGui::Checkbox("Reverse", &reverseFlag);
		static_cast<EnemySpawner*>(newObject)->SetIsReverse(reverseFlag);

		eKindsAmount = SetEnemyspawnerKindList(static_cast<EnemyKinds>(eKindsAmount));

		ImGui::EndChild();
		break;
	}

	for (auto& obj : GameManagers::Instance().GetObjectManager()->GetObjectMap())
	{
		if (obj.second.get()->isCollideWithPoint({ inputTest->GetMousePositionX(), inputTest->GetMousePositionY() }))

		{
			if (inputTest->IsMouseButtonPressed(RIGHT_BUTTON))
			{
				GameManagers::Instance().GetObjectManager()->Destroy(obj.first);
				break;
			}
			else if (inputTest->IsMouseButtonPressed(LEFT_BUTTON))
			{
				newObject->SetSpriteName(obj.second.get()->GetSpriteName());
				newObject->SetObjectType(obj.second.get()->GetObjectType());

				newObject->SetXPosition(obj.second.get()->GetPosition().x);
				newObject->SetYPosition(obj.second.get()->GetPosition().y);

				newObject->SetXSize(obj.second.get()->GetSize().x);
				newObject->SetXSize(obj.second.get()->GetSize().y);

				newObject->SetXSpeed(obj.second.get()->GetSpeed().x);
				newObject->SetYSpeed(obj.second.get()->GetSpeed().y);

				newObject->SetDepth(obj.second.get()->GetDepth());


				switch (obj.second.get()->GetObjectType())
				{
				case ObjectType::ENEMYSPAWNER:
					spawnDelayMaxAmount = static_cast<EnemySpawner*>(obj.second.get())->GetSpawnDelayMax();
					spawnDelayIncreasedAmount = static_cast<EnemySpawner*>(obj.second.get())->GetSpawnDelayIncreased();
					spawnAmountMaxAmount = static_cast<EnemySpawner*>(obj.second.get())->GetSpawnAmountMax();
					eKindsAmount = static_cast<EnemySpawner*>(obj.second.get())->GetEnemyKinds();
					break;
				}
				break;
			}
		}
	}

	if (mouseIsClickedWithoutObject == false && inputTest->IsMouseButtonPressed(MIDDLE_BUTTON))
	{
		mouseIsClickedWithoutObject = true;
		switch (newObject->GetObjectType())
		{
		case ObjectType::NONE:
			GameManagers::Instance().GetObjectManager()->AddObject<Object>(newObject->GetPosition().x, newObject->GetPosition().y
				, newObject->GetSpeed().x, newObject->GetSpeed().y, newObject->GetSize().x, newObject->GetSize().y, newObject->GetDrawType(), newName, ObjectType::NONE);
			GameManagers::Instance().GetObjectManager()->FindObjectWithName(newName)->SetSpriteName(newObject->GetSpriteName());
			GameManagers::Instance().GetObjectManager()->FindObjectWithName(newName)->SetDepth(newObject->GetDepth());
			break;
		case ObjectType::PLAYER:
			GameManagers::Instance().GetObjectManager()->AddObject<Player>(newObject->GetPosition().x, newObject->GetPosition().y
				, newObject->GetSpeed().x, newObject->GetSpeed().y, newObject->GetSize().x, newObject->GetSize().y, newObject->GetDrawType(), newName, ObjectType::NONE);
			GameManagers::Instance().GetObjectManager()->FindObjectWithName(newName)->SetSpriteName(newObject->GetSpriteName());
			GameManagers::Instance().GetObjectManager()->FindObjectWithName(newName)->SetDepth(newObject->GetDepth());
			break;
		case ObjectType::ENEMYSPAWNER:
			GameManagers::Instance().GetObjectManager()->AddObject<EnemySpawner>(newObject->GetPosition().x, newObject->GetPosition().y
				, newObject->GetSpeed().x, newObject->GetSpeed().y, newObject->GetSize().x, newObject->GetSize().y, newObject->GetDrawType(), newName, ObjectType::ENEMYSPAWNER);
			GameManagers::Instance().GetObjectManager()->GetObjectMap().at(GameManagers::Instance().GetObjectManager()->GetLastObjectID()).get()->SetSpriteName(newObject->GetSpriteName());
			GameManagers::Instance().GetObjectManager()->GetObjectMap().at(GameManagers::Instance().GetObjectManager()->GetLastObjectID()).get()->SetDepth(newObject->GetDepth());
			static_cast<EnemySpawner*>(GameManagers::Instance().GetObjectManager()->GetObjectMap().at(GameManagers::Instance().GetObjectManager()->GetLastObjectID()).get())->SetVariables(spawnDelayMaxAmount, spawnDelayIncreasedAmount, spawnAmountMaxAmount, static_cast<EnemyKinds>(eKindsAmount));
			static_cast<EnemySpawner*>(GameManagers::Instance().GetObjectManager()->GetObjectMap().at(GameManagers::Instance().GetObjectManager()->GetLastObjectID()).get())->SetSpawnPositionOffset(static_cast<EnemySpawner*>(newObject)->GetSpawnPositionOffset().x, static_cast<EnemySpawner*>(newObject)->GetSpawnPositionOffset().y);
			static_cast<EnemySpawner*>(GameManagers::Instance().GetObjectManager()->GetObjectMap().at(GameManagers::Instance().GetObjectManager()->GetLastObjectID()).get())->SetStopPositionOffSet(static_cast<EnemySpawner*>(newObject)->GetStopPositionOffSet().x, static_cast<EnemySpawner*>(newObject)->GetStopPositionOffSet().y);
			break;
		}
	}
	else if (mouseIsClickedWithoutObject == true && inputTest->IsMouseButtonReleased(MIDDLE_BUTTON))
	{
		mouseIsClickedWithoutObject = false;
	}

	switch (newObject->GetDrawType())
	{
	case DrawType::RECTANGLE:
		GameManagers::Instance().GetSpriteManager()->DrawRectangle(newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::RECTANGLELINE:
		GameManagers::Instance().GetSpriteManager()->DrawRectangleLine(newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::SPRITE:
		GameManagers::Instance().GetSpriteManager()->DrawSprite(newObject->GetSpriteName(), newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::SPRITEANIMATION:
		GameManagers::Instance().GetSpriteManager()->DrawSpriteWithAnimation(newObject->GetSpriteName(), Game::Instance().GetDeltaTime(), newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	}

	ImGui::End();
}


void MyImGui::BackgroundList()
{
	//ImGui::Begin("BackgroundList");
	//ImGui::BeginChild("Scrolling");
	//for (auto& group : BackgroundManager::Instance().GetSaveBackgroundList())
	//{
	//	for (auto& back : group.second)
	//	{
	//		if (ImGui::Selectable(group.first.c_str(), &back))
	//		{
	//			//targetB = back;
	//		}
	//	}
	//}
	//ImGui::EndChild();
	//ImGui::End();
	if (Game::Instance().GetGameState() == GameState::EDITOR && editMode == EditorMode::BACKGCREATOR)
	{
		BackgroundCreator();
	}
}

void MyImGui::BackgroundCreator()
{
	float  targetP[2] = { targetBackground->position.x, targetBackground->position.y };
	float  targetScale[2] = { targetBackground->size.x, targetBackground->size.y };
	float  targetSpeed[2] = { targetBackground->speed.x, targetBackground->speed.y };
	float targetAngle = targetBackground->angle;
	float targetDepth = targetBackground->depth;

	static int targetScaleAmount[2] = { 1, 1 };
	static bool isTiledScale = false;

	ImGui::Begin("BackgroundCreator");
	BackgroundtTypeList(targetBackground);
	SpriteList(targetBackground);

	static char newGroup[256] = "none";
	ImGui::InputText("default", newGroup, 256);
	backgroundGroup = newGroup;

	ImGui::InputFloat2("Position", targetP);
	vec2<float> newPosition = { inputTest->GetMousePositionX() - std::fmod(inputTest->GetMousePositionX(), targetBackground->size.x),  inputTest->GetMousePositionY() - std::fmod(inputTest->GetMousePositionY(), targetBackground->size.y) };
	targetBackground->position.x = newPosition.x;
	targetBackground->position.y = newPosition.y;

	ImGui::InputFloat2("Scale", targetScale);
	targetBackground->size.x = targetScale[0];
	targetBackground->size.y = targetScale[1];

	ImGui::InputFloat2("Speed", targetSpeed);
	targetBackground->speed.x = targetSpeed[0];
	targetBackground->speed.y = targetSpeed[1];

	ImGui::InputFloat("Angle", &targetAngle, 90.f, 360.0f);
	targetBackground->angle = targetAngle;

	ImGui::InputFloat("Depth", &targetDepth, 0.1f, 1.0f);
	targetBackground->depth = targetDepth;

	if (targetBackground->type == BackgroundType::NORMAL)
	{
		ImGui::Checkbox("TiledScale", &isTiledScale);
		if (isTiledScale == true)
		{
			ImGui::InputInt("X", &targetScaleAmount[0], 1, 1);
			ImGui::InputInt("Y", &targetScaleAmount[1], 1, 1);

			GameManagers::Instance().GetSpriteManager()->DrawRectangleLine({ targetP[0] + targetScale[0] * static_cast<float>(targetScaleAmount[0]), targetP[1] - targetScale[1] * static_cast<float>(targetScaleAmount[1]) }, 0.f, { targetScale[0] * static_cast<float>(targetScaleAmount[0]), targetScale[1] * static_cast<float>(targetScaleAmount[1]) }, {0.0f,0.f,0.5f,1.f});
		}
	}

	for (auto& group : BackgroundManager::Instance().GetSaveBackgroundList())
	{
		for (int i = 0; i < group.second.size(); i++)
		{
			if (!(group.second.at(i).position.x + group.second.at(i).size.x < inputTest->GetMousePositionX() || inputTest->GetMousePositionX() < group.second.at(i).position.x - group.second.at(i).size.x
				|| group.second.at(i).position.y + group.second.at(i).size.y < inputTest->GetMousePositionY() || inputTest->GetMousePositionY() < group.second.at(i).position.y - group.second.at(i).size.y) && inputTest->IsMouseButtonPressed(RIGHT_BUTTON))
			{
				group.second.erase(group.second.begin() + i);
				break;
			}
		}
	}

	if (mouseIsClickedWithoutObject == false && inputTest->IsMouseButtonPressed(MIDDLE_BUTTON))
	{
		mouseIsClickedWithoutObject = true;
		if (isTiledScale == false)
		{
			BackgroundManager::Instance().AddSaveBackgroundList(targetBackground->spriteName, backgroundGroup, targetBackground->type, targetBackground->position, targetBackground->size,
				targetBackground->angle, targetBackground->speed, { 0.f,0.f }, targetBackground->depth);
		}
		else
		{
			vec2<float> startPosition = { targetP[0] + targetBackground->size.x, targetP[1] - targetBackground->size.y };
			for (int width = 0; width < targetScaleAmount[0]; width++)
			{
				for (int height = 0; height < targetScaleAmount[1]; height++)
				{
					BackgroundManager::Instance().AddSaveBackgroundList(targetBackground->spriteName, backgroundGroup, targetBackground->type, startPosition, targetBackground->size,
						targetBackground->angle, targetBackground->speed, { 0.f,0.f }, targetBackground->depth);
					startPosition.y -= targetBackground->size.y * 2.f;
				}
				startPosition.x += targetBackground->size.x * 2.f;
				startPosition.y = targetP[1] - targetBackground->size.y;
			}
		}
	}
	else if (mouseIsClickedWithoutObject == true && inputTest->IsMouseButtonReleased(MIDDLE_BUTTON))
	{
		mouseIsClickedWithoutObject = false;
	}

	if (GameManagers::Instance().GetSpriteManager()->GetSprite(targetBackground->spriteName)->isAnimated == true)
	{
		GameManagers::Instance().GetSpriteManager()->DrawSpriteWithAnimation(targetBackground->spriteName, targetBackground->backgroundAnimation, Game::Instance().GetDeltaTime(), targetBackground->position, targetBackground->angle, targetBackground->size, {1.f,1.f,1.f,1.f}, targetBackground->depth);
	}
	else
	{
		GameManagers::Instance().GetSpriteManager()->DrawSprite(targetBackground->spriteName, targetBackground->position, targetBackground->angle, targetBackground->size, { 1.f,1.f,1.f,1.f }, targetBackground->depth);
	}
	
	ImGui::End();
}

void MyImGui::LevelEditor()
{
	ImGui::Begin("LevelEditor");
	if (ImGui::Button("LevelSave"))
	{
		SaveLevelData();
	}

	/*if (ImGui::Button("EnemySpawner"))
	{
		GameManagers::Instance().GetObjectManager()->AddObject<EnemySpawner>(GameManagers::Instance().GetCameraManager()->GetCenter().x, GameManagers::Instance().GetCameraManager()->GetCenter().y, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "EnemySpawner", ObjectType::ENEMYSPAWNER);
	}*/

	if (ImGui::Button("Mode:ObjectModifier"))
	{
		editMode = EditorMode::OBJMODIFIER;
	}
	if (ImGui::Button("Mode:ObjectCreator"))
	{
		editMode = EditorMode::OBJCREATOR;
	}
	if (ImGui::Button("Mode:BackgroundCreator"))
	{
		editMode = EditorMode::BACKGCREATOR;
	}

	ImGui::End();
}
#endif

#ifdef _DEBUG
void MyImGui::MouseInputEvent()
{
	if (Game::Instance().GetGameState() == GameState::EDITOR)
	{
		if (target != nullptr && editMode == EditorMode::OBJMODIFIER)
		{
			if (targetIsClicked == true && inputTest->IsMouseButtonPressed(LEFT_BUTTON))
			{
				target->SetXPosition(inputTest->GetMousePositionX());
				target->SetYPosition(inputTest->GetMousePositionY());
				target->SetMinMax();
			}
			else if (mouseIsClickedWithoutObject == false && targetIsClicked == false && inputTest->IsMouseButtonPressed(LEFT_BUTTON) && target->isCollideWithPoint({ inputTest->GetMousePositionX(), inputTest->GetMousePositionY() }) == false)
			{
				mouseIsClickedWithoutObject = true;
				//GameManagers::Instance().GetCameraManager()->TargetAt({ inputTest.GetMousePositionX(), inputTest.GetMousePositionY() });
			}
			else if (mouseIsClickedWithoutObject == true && targetIsClicked == false && inputTest->IsMouseButtonReleased(LEFT_BUTTON))
			{
				mouseIsClickedWithoutObject = false;
			}

			if (targetIsClicked == true && inputTest->IsMouseButtonReleased(LEFT_BUTTON))
			{
				targetIsClicked = false;
			}
		}
		else if (editMode == EditorMode::BACKGCREATOR)
		{
		}
	}
	else
	{
	}

	//auto window = GameManagers::Instance().GetPlatformWindow()->GetWindow();
	//int winX = 0;
	//int winY = 0;
	//int range = 50;
	//glfwGetWindowSize(window, &winX, &winY);
	//float cameraXSize = ((((GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().x / 2) / ((winX / 2) - 1)) * (GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().x / 2) / GameManagers::Instance().GetCameraManager()->GetZoom()));
	//float cameraYSize = -((-((GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().y / 2) / ((winY / 2) - 1)) * (GameManagers::Instance().GetPlatformWindow()->GetPlatformWindowViewSize().y / 2) / GameManagers::Instance().GetCameraManager()->GetZoom()));

	//std::cout << cameraYSize << std::endl;
	//if (inputTest.GetMousePositionX() >= cameraXSize + GameManagers::Instance().GetCameraManager()->GetCenter().x - range)
	//{
	//	GameManagers::Instance().GetCameraManager()->TargetAt({ GameManagers::Instance().GetCameraManager()->GetCenter().x + 2.f,  GameManagers::Instance().GetCameraManager()->GetCenter().y });
	//}
	//else if (inputTest.GetMousePositionX() <= -cameraXSize + GameManagers::Instance().GetCameraManager()->GetCenter().x + range)
	//{
	//	GameManagers::Instance().GetCameraManager()->TargetAt({ GameManagers::Instance().GetCameraManager()->GetCenter().x - 2.f,  GameManagers::Instance().GetCameraManager()->GetCenter().y});
	//}
	//if (inputTest.GetMousePositionY() >= cameraYSize + GameManagers::Instance().GetCameraManager()->GetCenter().y - range)
	//{
	//	GameManagers::Instance().GetCameraManager()->TargetAt({ GameManagers::Instance().GetCameraManager()->GetCenter().x ,  GameManagers::Instance().GetCameraManager()->GetCenter().y + 2.f });
	//}
	//else if (inputTest.GetMousePositionY() <= -cameraYSize + GameManagers::Instance().GetCameraManager()->GetCenter().y + range)
	//{
	//	GameManagers::Instance().GetCameraManager()->TargetAt({ GameManagers::Instance().GetCameraManager()->GetCenter().x,  GameManagers::Instance().GetCameraManager()->GetCenter().y - 2.f });
	//}
}

void MyImGui::DrawTypeList(Object* object)
{
	if (ImGui::BeginCombo("DrawType", DrawTypeEnumToChar(object->GetDrawType())))
	{
		if (ImGui::Selectable(DrawTypeEnumToChar(DrawType::NONE), false))
		{
			object->SetDrawType(DrawType::NONE);
			if (object->GetDrawType() == DrawType::NONE)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		if (ImGui::Selectable(DrawTypeEnumToChar(DrawType::RECTANGLE), false))
		{
			object->SetDrawType(DrawType::RECTANGLE);
			if (object->GetDrawType() == DrawType::RECTANGLE)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		if (ImGui::Selectable(DrawTypeEnumToChar(DrawType::RECTANGLELINE), false))
		{
			object->SetDrawType(DrawType::RECTANGLELINE);
			if (object->GetDrawType() == DrawType::RECTANGLELINE)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		if (ImGui::Selectable(DrawTypeEnumToChar(DrawType::SPRITE), false))
		{
			object->SetDrawType(DrawType::SPRITE);
			if (object->GetDrawType() == DrawType::SPRITE)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		if (ImGui::Selectable(DrawTypeEnumToChar(DrawType::SPRITEANIMATION), false))
		{
			object->SetDrawType(DrawType::SPRITEANIMATION);
			if (object->GetDrawType() == DrawType::SPRITEANIMATION)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}

void MyImGui::ObjectTypeList(Object* object)
{
	if (ImGui::BeginCombo("ObjectType", ObjectTypeEnumToChar(object->GetObjectType())))
	{
		if (ImGui::Selectable(ObjectTypeEnumToChar(ObjectType::PLAYER), false))
		{
			object->SetObjectType(ObjectType::PLAYER);
			ImGui::SetItemDefaultFocus();
		}
		if (ImGui::Selectable(ObjectTypeEnumToChar(ObjectType::ENEMYSPAWNER), false))
		{
			object->SetObjectType(ObjectType::ENEMYSPAWNER);
			ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
}

void MyImGui::BackgroundtTypeList(Background* target_)
{
	if (ImGui::BeginCombo("BackgroundtTypeList", BackgroundTypeEnumToChar(target_->type)))
	{
		for (int i = 0; i < BackgroundType::NONE; i++)
		{
			if (ImGui::Selectable(BackgroundTypeEnumToChar(static_cast<BackgroundType>(i)), i))
			{
				target_->type = static_cast<BackgroundType>(i);
			}
			if (target_->type == static_cast<BackgroundType>(i))
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}

void MyImGui::EnemyspawnerKindList(Object* object)
{
	if (ImGui::BeginCombo("EnemySpawnKinds", EnemyKindEnumToChar(static_cast<EnemyKinds>(static_cast<EnemySpawner*>(object)->GetEnemyKinds()))))
	{
		for (int i = 0; i < EnemyKinds::LAST; i++)
		{
			if (ImGui::Selectable(EnemyKindEnumToChar(static_cast<EnemyKinds>(i)), i))
			{
				static_cast<EnemySpawner*>(object)->SetEnemyKinds(static_cast<EnemyKinds>(i));
			}
			if (static_cast<EnemySpawner*>(object)->GetEnemyKinds() == static_cast<EnemyKinds>(i))
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}

void MyImGui::SpriteList(Object* object)
{
	if (GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).isAnimated == true)
	{
		ImGui::Image((void*)(intptr_t)GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).texture.GetTexturehandle(), 
			ImVec2(128, 128), ImVec2(0.0f, 1.0f), ImVec2(1.0f / static_cast<float>(GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).animation.GetFrameIndexX()), 0.0f));
	}
	else
	{
		ImGui::Image((void*)(intptr_t)GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).texture.GetTexturehandle(), ImVec2(128, 128)
		, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
	}
	if (ImGui::BeginCombo("SpriteList", object->GetSpriteName().c_str()))
	{
		int index = 0;
		for (auto sprite : GameManagers::Instance().GetSpriteManager()->GetSpriteMap())
		{
			if (ImGui::Selectable(sprite.first.c_str(), index))
			{
				object->SetSpriteName(sprite.first.c_str());
				if (sprite.second.isAnimated == true)
				{
					object->SetDrawType(DrawType::SPRITEANIMATION);
				}
				else
				{
					object->SetDrawType(DrawType::SPRITE);
				}
			}
			if (sprite.first.c_str() == object->GetSpriteName().c_str())
			{
				ImGui::SetItemDefaultFocus();
			}
			index++;

		}
		ImGui::EndCombo();
	}
}

void MyImGui::SpriteList(Background* back)
{
	if (GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).isAnimated == true)
	{
		ImGui::Image((void*)(intptr_t)GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).texture.GetTexturehandle(),
			ImVec2(128, 128), ImVec2(0.0f, 1.0f), ImVec2(1.0f / static_cast<float>(GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).animation.GetFrameIndexX()), 0.0f));
	}
	else
	{
		ImGui::Image((void*)(intptr_t)GameManagers::Instance().GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).texture.GetTexturehandle(), ImVec2(128, 128)
			, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
	}
	if (ImGui::BeginCombo("SpriteList", back->spriteName.c_str()))
	{
		int index = 0;
		for (auto sprite : GameManagers::Instance().GetSpriteManager()->GetSpriteMap())
		{
			if (ImGui::Selectable(sprite.first.c_str(), index))
			{
				back->spriteName = sprite.first;
				if (sprite.second.isAnimated == true)
				{
					back->backgroundAnimation = GameManagers::Instance().GetSpriteManager()->GetSprite(back->spriteName)->animation;
				}
			}
			if (sprite.first.c_str() == back->spriteName.c_str())
			{
				ImGui::SetItemDefaultFocus();
			}
			index++;
		}
		ImGui::EndCombo();
	}
}

void MyImGui::SaveLevelData()
{
	switch (GameManagers::Instance().GetStateManager()->GetCurrentLevel())
	{
	case GameLevel::Demo:
		fileIO::SaveLevelData("../GameEngine/Level/LevelData/GameDemo.lvl");
		break;
	case GameLevel::LEVEL1:
		fileIO::SaveLevelData("../GameEngine/Level/LevelData/Level1.lvl");
		break;
	}
}
#endif
