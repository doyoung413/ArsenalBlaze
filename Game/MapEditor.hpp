#pragma once
#pragma warning(push)
#pragma warning(disable:26451)
#pragma warning(disable:26495)
#include "imgui.h"
#include "glm.hpp"
#include "Object/EnemyType.hpp"

#include <string>
#pragma warning (pop)

enum EditorMode
{
	OBJMODIFIER,
	OBJCREATOR,
	BACKGCREATOR
};

enum class EnemyType;
class Object;
struct Background;
class MapEditor
{
public:
	void Init();
	void Update();
	void End();
private:
	void ObjectList();
	void ObjectModifier();
	void ObjectCreator();
	void EnemyTypeList();

	void BackgroundList();
	void BackgroundCreator();
	void BackgroundtTypeList(Background* target_);

	void LevelEditor();

	void MouseInputEvent();
	void ObjectTypeList(Object* object);
	void DrawTypeList(Object* object);

	void SpriteList(Object* object);
	void SpriteList(Background* back);
	void SaveLevelData();

	bool isCollideWithPoint(glm::vec2 point, Object* object);

	Object* target = nullptr;
	Object* newObject = nullptr;
	std::string newObjectName = "";

	EnemyType enemyType = EnemyType::TOWARD;
	glm::vec2 spawnPosition = { 0.f,0.f };
	glm::vec2 spawnPositionOffset = { 0.f,0.f };
	glm::vec2 stopPositionOffset = { 0.f,0.f };
	bool isReverseMove = false;

	int backgroundCurrentIndex = 0;

	Background* targetBackground;
	std::string backgroundGroup = "";

	bool targetIsClicked = false;
	bool mouseIsClickedWithoutObject = false;
	bool isPositionFree = false;

	EditorMode editMode = EditorMode::OBJMODIFIER;
};
