#ifdef _DEBUG
#include "MapEditor.hpp"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"

#include "Instance.hpp"

#include "FileManager.hpp"

#include "Object/Player.hpp"

#include "Object/Enemy.hpp"
#include "Object/EnemyToward.hpp"
#include "Object/EnemyTowardA.hpp"
#include "Object/EnemyMoveS.hpp"
#include "Object/EnemyMoveU.hpp"
#include "Object/EnemySideAppear.hpp"
#include "Object/EnemyRobotA.hpp"
#include "Object/EnemyBigA.hpp"

#include <cmath>
#include <iostream>
#endif


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
	case ObjectType::ENEMY:
		return "ENEMY";
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
#endif

#ifdef _DEBUG
void MapEditor::Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL(Instance::GetWindow()->GetWindow(), Instance::GetWindow()->GetGLContext());
	ImGui_ImplOpenGL3_Init("#version 100");
	if (Instance::GetObjectManager()->GetObjectMap().empty() == false)
	{
		target = Instance::GetObjectManager()->GetObjectMap().begin()->second.get();
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
	newObject->SetDrawType(DrawType::RECTANGLE);
	newObject->AddComponent<Physics>();
}
#endif

#ifdef _DEBUG
void MapEditor::Update()
{
	Instance::GetSpriteManager()->DrawRectangleLine({ 0.f, 0.f, 0.f }, 0.f, { Instance::GetCameraManager()->GetViewSize().x / 2.f, Instance::GetCameraManager()->GetViewSize().y / 2.f, 0.f }, { 0.5f,1.f,0.5f,1.f });
	if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::M))
	{
		if (Instance::GetGameManager()->GetGameMode() != GameMode::EDITOR)
		{
			Instance::GetLevelManager()->RestartLevel();
			Instance::GetGameManager()->SetGameMode(GameMode::EDITOR);
		}
		else
		{
			Instance::GetLevelManager()->RestartLevel();
			Instance::GetGameManager()->SetGameMode(GameMode::RUNNING);
		}
	}
	ImGui_ImplSDL2_ProcessEvent(&Instance::GetWindow()->GetEvent());
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Input");
	ImGui::Text("X:%f Y:%f", Instance::GetInputManager()->GetMousePosition().x, Instance::GetInputManager()->GetMousePosition().y);


	if (Instance::GetGameManager()->GetGameMode() == GameMode::EDITOR)
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

	ImGui::End();
	//rendering
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//rendering
}
#endif

#ifdef _DEBUG
void MapEditor::End()
{
	delete targetBackground;
	delete newObject;
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void MapEditor::ObjectList()
{
	ImGui::Begin("ObjectList");
	ImGui::BeginChild("Scrolling");
	for (auto& obj : Instance::GetObjectManager()->GetObjectMap())
	{
		if (Instance::GetGameManager()->GetGameMode() == GameMode::EDITOR)
		{
			if (isCollideWithPoint({ Instance::GetInputManager()->GetMousePosition().x, Instance::GetInputManager()->GetMousePosition().y }, obj.second.get())
				&& Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT))
				if (targetIsClicked == false && target == obj.second.get())
				{
					targetIsClicked = true;
				}
				else if (targetIsClicked == false && target != obj.second.get())
				{
					target = obj.second.get();
					Instance::GetCameraManager()->TargetAt(target->GetPosition());
				}
		}
		if (ImGui::Selectable(obj.second->GetName().c_str(), &obj.second))
		{
			editMode = EditorMode::OBJMODIFIER;
			target = obj.second.get();
			Instance::GetCameraManager()->TargetAt(target->GetPosition());
			targetIsClicked = true;
		}
	}
	ImGui::EndChild();
	ImGui::End();
	if (Instance::GetGameManager()->GetGameMode() == GameMode::EDITOR)
	{
		if (editMode == EditorMode::OBJMODIFIER)
		{
			ObjectModifier();
			Instance::GetSpriteManager()->DrawRectangleLine(target->GetPosition(), 0.f, target->GetSize(), { 1.0f, 0.0f, 0.0f, 1.f }, 1.f);
		}
		if (editMode == EditorMode::OBJCREATOR)
		{
			ObjectCreator();
		}
	}
}

void MapEditor::ObjectModifier()
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
		ImGui::InputFloat("Rotate", &angle, -360.0f, 360.0f);
		target->SetRotate(angle);

		Color4f color = target->GetColor();
		ImGui::ColorEdit4("clear color", (float*)&color);
		target->SetColor(color);


		ImGui::End();
	}
}

void MapEditor::ObjectCreator()
{
	float  targetP[2] = { newObject->GetPosition().x, newObject->GetPosition().y };
	float  targetScale[2] = { newObject->GetSize().x, newObject->GetSize().y };
	float  targetSpeed[2] = { newObject->GetSpeed().x, newObject->GetSpeed().y };
	float targetDepth = newObject->GetDepth();
	static char newName[256] = "none";

	static float  offsetSpawnT[2] = { spawnPositionOffset.x, spawnPositionOffset.y };
	static float  offsetStopT[2] = { stopPositionOffset.x, stopPositionOffset.y };

	ImGui::Begin("ObjectCreator");
	ObjectTypeList(newObject);
	switch (newObject->GetObjectType())
	{
	case ObjectType::PLAYER:
		break;
	case ObjectType::ENEMY:
		ImGui::BeginChild("Enemy");
		EnemyTypeList();
		ImGui::InputFloat2("offsetSpawn", offsetSpawnT);
		ImGui::InputFloat2("offsetStop", offsetStopT);

		ImGui::Checkbox("Reverse", &isReverseMove);
		ImGui::EndChild();
		break;
	default:
		SpriteList(newObject);
		DrawTypeList(newObject);
		ImGui::InputText("default", newName, 256);
		newObjectName = newName;

		ImGui::InputFloat2("Position", targetP);

		ImGui::InputFloat2("Scale", targetScale);
		glm::vec2 newSize = { targetScale[0], targetScale[1] };
		newObject->SetXSize(newSize.x);
		newObject->SetYSize(newSize.y);

		ImGui::InputFloat2("Speed", targetSpeed);
		glm::vec2 newSpeed = { targetSpeed[0], targetSpeed[1] };
		newObject->SetXSpeed(newSpeed.x);
		newObject->SetYSpeed(newSpeed.y);

		ImGui::InputFloat("Depth", &targetDepth, 0.1f, 1.0f);
		newObject->SetDepth(targetDepth);
		break;
	}
	glm::vec2 newPosition = { Instance::GetInputManager()->GetMousePosition().x - std::fmod(Instance::GetInputManager()->GetMousePosition().x, targetBackground->size.x),  Instance::GetInputManager()->GetMousePosition().y - std::fmod(Instance::GetInputManager()->GetMousePosition().y, targetBackground->size.y) };
	newObject->SetXPosition(newPosition.x);
	newObject->SetYPosition(newPosition.y);

	for (auto& obj : Instance::GetObjectManager()->GetObjectMap())
	{
		if (isCollideWithPoint({ Instance::GetInputManager()->GetMousePosition().x, Instance::GetInputManager()->GetMousePosition().y }, obj.second.get()))

		{
			if (Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::RIGHT))
			{
				Instance::GetObjectManager()->Destroy(obj.first);
				break;
			}
			else if (Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT))
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
				break;
			}
		}
	}

	if (mouseIsClickedWithoutObject == false && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::MIDDLE))
	{
		mouseIsClickedWithoutObject = true;
		switch (newObject->GetObjectType())
		{
		case ObjectType::NONE:
			Instance::GetObjectManager()->AddObject<Object>(newObject->GetPosition().x, newObject->GetPosition().y
				, newObject->GetSpeed().x, newObject->GetSpeed().y, newObject->GetSize().x, newObject->GetSize().y, newObject->GetDrawType(), newName, ObjectType::NONE);
			Instance::GetObjectManager()->FindObjectWithName(newName)->SetSpriteName(newObject->GetSpriteName());
			Instance::GetObjectManager()->FindObjectWithName(newName)->SetDepth(newObject->GetDepth());
			break;
		case ObjectType::PLAYER:
			Instance::GetObjectManager()->AddObject<Player>(newObject->GetPosition().x, newObject->GetPosition().y
				, newObject->GetSpeed().x, newObject->GetSpeed().y, newObject->GetSize().x, newObject->GetSize().y, newObject->GetDrawType(), newName, ObjectType::NONE);
			Instance::GetObjectManager()->FindObjectWithName(newName)->SetSpriteName(newObject->GetSpriteName());
			Instance::GetObjectManager()->FindObjectWithName(newName)->SetDepth(newObject->GetDepth());
			break;
		case ObjectType::ENEMY:
			switch (enemyType)
			{
			case EnemyType::TOWARD:
				Instance::GetObjectManager()->AddObject<EnemyToward>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				break;
			case EnemyType::TOAWRD_A:
				Instance::GetObjectManager()->AddObject<EnemyTowardA>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				break;
			case EnemyType::MOVE_S:
				Instance::GetObjectManager()->AddObject<EnemyMoveS>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				static_cast<EnemyMoveS*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(isReverseMove);
				break;
			case EnemyType::MOVE_U:
				Instance::GetObjectManager()->AddObject<EnemyMoveU>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				static_cast<EnemyMoveU*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(isReverseMove);
				break;
			case EnemyType::SIDE_APPEAR:
				Instance::GetObjectManager()->AddObject<EnemySideAppear>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				static_cast<EnemySideAppear*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(isReverseMove);
				break;
			case EnemyType::ROBOT_A:
				Instance::GetObjectManager()->AddObject<EnemyRobotA>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				static_cast<EnemyRobotA*>(Instance::GetObjectManager()->GetLastObject())->SetMoveReverse(isReverseMove);
				break;
			case EnemyType::BIG_A:
				Instance::GetObjectManager()->AddObject<EnemyBigA>(newObject->GetPosition().x, newObject->GetPosition().y
					, newObject->GetSpeed().x, newObject->GetSpeed().y, 32.f, 32.f, newObject->GetDrawType(), newName, spawnPositionOffset, stopPositionOffset);
				break;
			}
			break;
		}
	}
	else if (mouseIsClickedWithoutObject == true && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::MIDDLE) == false)
	{
		mouseIsClickedWithoutObject = false;
	}

	switch (newObject->GetDrawType())
	{
	case DrawType::RECTANGLE:
		Instance::GetSpriteManager()->DrawRectangle(newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::RECTANGLELINE:
		Instance::GetSpriteManager()->DrawRectangleLine(newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::SPRITE:
		Instance::GetSpriteManager()->DrawSprite(newObject->GetSpriteName(), newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	case DrawType::SPRITEANIMATION:
		Instance::GetSpriteManager()->DrawSpriteWithAnimation(newObject->GetSpriteName(), 1.f, newObject->GetPosition(), 0.f, newObject->GetSize(), { 1.f,1.f,1.f,1.f }, newObject->GetDepth());
		break;
	}

	ImGui::End();
}

void MapEditor::EnemyTypeList()
{
	if (ImGui::BeginCombo("EnemyTypeList", EnemyTypeEnumToChar(enemyType)))
	{
		for (int i = 0; i < static_cast<int>(EnemyType::NONE); i++)
		{
			if (ImGui::Selectable(EnemyTypeEnumToChar(static_cast<EnemyType>(i)), i))
			{
				enemyType = static_cast<EnemyType>(i);
			}
			if (enemyType == static_cast<EnemyType>(i))
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}


void MapEditor::BackgroundList()
{
	//ImGui::Begin("BackgroundList");
	//ImGui::BeginChild("Scrolling");
	//for (auto& group : Instance::GetBackgroundManager()->GetSaveBackgroundList())
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
	if (Instance::GetGameManager()->GetGameMode() == GameMode::EDITOR && editMode == EditorMode::BACKGCREATOR)
	{
		BackgroundCreator();
	}
}

void MapEditor::BackgroundCreator()
{

	float  targetP[2] = { targetBackground->position.x, targetBackground->position.y };
	float  targetScale[2] = { targetBackground->size.x, targetBackground->size.y };
	float  targetSpeed[2] = { targetBackground->speed.x, targetBackground->speed.y };
	float targetAngle = targetBackground->angle;
	float targetDepth = targetBackground->depth;

	static int targetScaleAmount[2] = { 1, 1 };
	static int tempHeight = targetBackground->towerHeight;
	static bool isTiledScale = false;

	ImGui::Begin("BackgroundCreator");
	ImGui::Checkbox("FreePosition", &isPositionFree);

	BackgroundtTypeList(targetBackground);
	SpriteList(targetBackground);

	static char newGroup[256] = "none";
	ImGui::InputText("default", newGroup, 256);
	backgroundGroup = newGroup;

	ImGui::InputFloat2("Position", targetP);
	glm::vec2 newPosition = { 0.f, 0.f };
	if (isPositionFree == false)
	{
		newPosition = { Instance::GetInputManager()->GetMousePosition().x - std::fmod(Instance::GetInputManager()->GetMousePosition().x, targetBackground->size.x),  Instance::GetInputManager()->GetMousePosition().y - std::fmod(Instance::GetInputManager()->GetMousePosition().y, targetBackground->size.y) };
	}
	else
	{
		newPosition = { Instance::GetInputManager()->GetMousePosition().x, Instance::GetInputManager()->GetMousePosition().y };
	}
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

	ImGui::Checkbox("isScrolled", &targetBackground->isScrolled);

	if (targetBackground->type == BackgroundType::NORMAL)
	{
		ImGui::Checkbox("TiledScale", &isTiledScale);
		if (isTiledScale == true)
		{
			ImGui::InputInt("X", &targetScaleAmount[0], 1, 1);
			ImGui::InputInt("Y", &targetScaleAmount[1], 1, 1);

			Instance::GetSpriteManager()->DrawRectangleLine({ targetP[0] + targetScale[0] * static_cast<float>(targetScaleAmount[0]), targetP[1] - targetScale[1] * static_cast<float>(targetScaleAmount[1]), 0.f }, 0.f, { targetScale[0] * static_cast<float>(targetScaleAmount[0]), targetScale[1] * static_cast<float>(targetScaleAmount[1]), 0.f }, { 0.0f,0.f,0.5f,1.f });
		}
	}

	for (auto& group : Instance::GetBackgroundManager()->GetSaveBackgroundList())
	{
		for (int i = 0; i < group.second.size(); i++)
		{
			if (!(group.second.at(i).position.x + group.second.at(i).size.x < Instance::GetInputManager()->GetMousePosition().x || Instance::GetInputManager()->GetMousePosition().x < group.second.at(i).position.x - group.second.at(i).size.x
				|| group.second.at(i).position.y + group.second.at(i).size.y < Instance::GetInputManager()->GetMousePosition().y || Instance::GetInputManager()->GetMousePosition().y < group.second.at(i).position.y - group.second.at(i).size.y) && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::RIGHT))
			{
				group.second.erase(group.second.begin() + i);
				break;
			}
		}
	}

	if (mouseIsClickedWithoutObject == false && (Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::MIDDLE) || Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::SPACE)))
	{
		mouseIsClickedWithoutObject = true;
		if (isTiledScale == false)
		{
			Instance::GetBackgroundManager()->AddSaveBackgroundList(targetBackground->spriteName, backgroundGroup, targetBackground->type, targetBackground->position, targetBackground->size,
				targetBackground->angle, targetBackground->speed, { 0.f,0.f }, targetBackground->depth/*, targetBackground->isScrolled*/);
		}
		else
		{
			glm::vec2 startPosition = { targetP[0] + targetBackground->size.x, targetP[1] - targetBackground->size.y };
			for (int width = 0; width < targetScaleAmount[0]; width++)
			{
				for (int height = 0; height < targetScaleAmount[1]; height++)
				{
					Instance::GetBackgroundManager()->AddSaveBackgroundList(targetBackground->spriteName, backgroundGroup, targetBackground->type, startPosition, targetBackground->size,
						targetBackground->angle, targetBackground->speed, { 0.f,0.f }, targetBackground->depth/*, targetBackground->isScrolled*/);
					startPosition.y -= targetBackground->size.y * 2.f;
				}
				startPosition.x += targetBackground->size.x * 2.f;
				startPosition.y = targetP[1] - targetBackground->size.y;
			}
		}
	}
	else if (mouseIsClickedWithoutObject == true && (Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::MIDDLE) == false || Instance::GetInputManager()->IsKeyPressed(KEYBOARDKEYS::SPACE) == false))
	{
		mouseIsClickedWithoutObject = false;
	}

	if (Instance::GetSpriteManager()->GetSprite(targetBackground->spriteName)->isAnimated == true)
	{
		Instance::GetSpriteManager()->DrawSpriteWithAnimation(targetBackground->spriteName, targetBackground->backgroundAnimation, 1.f, { targetBackground->position, 0.f }, targetBackground->angle, { targetBackground->size, 0.f }, { 1.f,1.f,1.f,1.f }, targetBackground->depth);
	}
	else
	{
		Instance::GetSpriteManager()->DrawSprite(targetBackground->spriteName, { targetBackground->position, 0.f }, targetBackground->angle, { targetBackground->size, 0.f }, { 1.f,1.f,1.f,1.f }, targetBackground->depth);
	}

	ImGui::End();
}

void MapEditor::LevelEditor()
{
	ImGui::Begin("LevelEditor");
	if (ImGui::Button("LevelSave"))
	{
		SaveLevelData();
	}

	/*if (ImGui::Button("EnemySpawner"))
	{
		Instance::GetObjectManager()->AddObject<EnemySpawner>(Instance::GetCameraManager()->GetCenter().x, Instance::GetCameraManager()->GetCenter().y, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "EnemySpawner", ObjectType::ENEMYSPAWNER);
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
void MapEditor::MouseInputEvent()
{
	if (Instance::GetGameManager()->GetGameMode() == GameMode::EDITOR)
	{
		if (target != nullptr && editMode == EditorMode::OBJMODIFIER)
		{
			if (targetIsClicked == true && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT))
			{
				target->SetXPosition(Instance::GetInputManager()->GetMousePosition().x);
				target->SetYPosition(Instance::GetInputManager()->GetMousePosition().y);
				target->Update(1.f);
			}
			else if (mouseIsClickedWithoutObject == false && targetIsClicked == false && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT) && isCollideWithPoint({ Instance::GetInputManager()->GetMousePosition().x, Instance::GetInputManager()->GetMousePosition().y }, target) == false)
			{
				mouseIsClickedWithoutObject = true;
				//Instance::GetCameraManager()->TargetAt({ inputTest.GetMousePosition().x, inputTest.GetMousePosition().y });
			}
			else if (mouseIsClickedWithoutObject == true && targetIsClicked == false && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT) == false)
			{
				mouseIsClickedWithoutObject = false;
			}

			if (targetIsClicked == true && Instance::GetInputManager()->IsMouseButtonPressed(MOUSEBUTTON::LEFT) == false)
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

}

void MapEditor::DrawTypeList(Object* object)
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

void MapEditor::ObjectTypeList(Object* object)
{
	if (ImGui::BeginCombo("ObjectType", ObjectTypeEnumToChar(object->GetObjectType())))
	{
		if (ImGui::Selectable(ObjectTypeEnumToChar(ObjectType::PLAYER), false))
		{
			object->SetObjectType(ObjectType::PLAYER);
			ImGui::SetItemDefaultFocus();
		}
		if (ImGui::Selectable(ObjectTypeEnumToChar(ObjectType::ENEMY), false))
		{
			object->SetObjectType(ObjectType::ENEMY);
			ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
}

void MapEditor::BackgroundtTypeList(Background* target_)
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

void MapEditor::SpriteList(Object* object)
{
	if (Instance::GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).isAnimated == true)
	{
		ImGui::Image((void*)(intptr_t)Instance::GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).texture.GetTexturehandle(),
			ImVec2(128, 128), ImVec2(0.0f, 1.0f), ImVec2(1.0f / static_cast<float>(Instance::GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).animation.GetFrameIndexX()), 0.0f));
	}
	else
	{
		ImGui::Image((void*)(intptr_t)Instance::GetSpriteManager()->GetSpriteMap().at(object->GetSpriteName().c_str()).texture.GetTexturehandle(), ImVec2(128, 128)
			, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
	}
	if (ImGui::BeginCombo("SpriteList", object->GetSpriteName().c_str()))
	{
		for (auto& sprite : Instance::GetSpriteManager()->GetSpriteMap())
		{
			int index = 0;
			const bool is_selected = sprite.first.c_str() == object->GetSpriteName().c_str();
			if (ImGui::Selectable(sprite.first.c_str()))
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
			if (is_selected)
			{
				ImGui::SetItemDefaultFocus();
			}
			index++;
		}
		ImGui::EndCombo();
	}
}

void MapEditor::SpriteList(Background* back)
{
	if (Instance::GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).isAnimated == true)
	{
		ImGui::Image((void*)(intptr_t)Instance::GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).texture.GetTexturehandle(),
			ImVec2(128, 128), ImVec2(0.0f, 1.0f), ImVec2(1.0f / static_cast<float>(Instance::GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).animation.GetFrameIndexX()), 0.0f));
	}
	else
	{
		ImGui::Image((void*)(intptr_t)Instance::GetSpriteManager()->GetSpriteMap().at(back->spriteName.c_str()).texture.GetTexturehandle(), ImVec2(128, 128)
			, ImVec2(0.0f, 1.0f), ImVec2(1.0f, 0.0f));
	}
	if (ImGui::BeginCombo("SpriteList", back->spriteName.c_str()))
	{
		int index = 0;
		for (auto sprite : Instance::GetSpriteManager()->GetSpriteMap())
		{
			if (ImGui::Selectable(sprite.first.c_str(), index))
			{
				backgroundCurrentIndex = index;
				back->spriteName = sprite.first;
				if (sprite.second.isAnimated == true)
				{
					back->backgroundAnimation = Instance::GetSpriteManager()->GetSprite(back->spriteName)->animation;
				}
			}
			if (sprite.first.c_str() == back->spriteName.c_str())
			{
				backgroundCurrentIndex = index;
				ImGui::SetItemDefaultFocus();
			}
			index++;
		}

		ImGui::EndCombo();
	}

	ImGui::SameLine();
	if (ImGui::Button("-"))
	{
		int temp = 0;
		if (backgroundCurrentIndex >= 0)
		{
			backgroundCurrentIndex--;
			if (backgroundCurrentIndex < 0)
			{
				backgroundCurrentIndex = static_cast<int>(Instance::GetSpriteManager()->GetSpriteMap().size()) - 1;
			}
		}
		for (auto sprite : Instance::GetSpriteManager()->GetSpriteMap())
		{
			if (backgroundCurrentIndex == temp)
			{
				back->spriteName = sprite.first;
				if (sprite.second.isAnimated == true)
				{
					back->backgroundAnimation = Instance::GetSpriteManager()->GetSprite(back->spriteName)->animation;
				}
				break;
			}
			temp++;
		}
	}
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		int temp = 0;
		if (backgroundCurrentIndex < Instance::GetSpriteManager()->GetSpriteMap().size())
		{
			backgroundCurrentIndex++;
		}
		for (auto sprite : Instance::GetSpriteManager()->GetSpriteMap())
		{
			if (backgroundCurrentIndex == temp)
			{
				back->spriteName = sprite.first;
				if (sprite.second.isAnimated == true)
				{
					back->backgroundAnimation = Instance::GetSpriteManager()->GetSprite(back->spriteName)->animation;
				}
				break;
			}
			temp++;
		}
	}
}

void MapEditor::SaveLevelData()
{
	FileManager::SaveLevelData("Game/Level/LevelData/Level1.lvl");
	switch (Instance::GetLevelManager()->GetCurrentLevel())
	{
	case LevelType::STAGE_1:
		FileManager::SaveLevelData("Game/Level/LevelData/Level1.lvl");
		break;
	}
}
bool MapEditor::isCollideWithPoint(glm::vec2 point, Object* object)
{
	return !((object->GetPosition().x + object->GetSize().x) < point.x || point.x < (object->GetPosition().x - object->GetSize().x)
		|| (object->GetPosition().y + object->GetSize().y) < point.y || point.y < (object->GetPosition().y - object->GetSize().y));
}
#endif
