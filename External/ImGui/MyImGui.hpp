#pragma once
#pragma warning(push)
#pragma warning(disable:26451)
#pragma warning(disable:26495)
#include <glfw3.h>
#include "../ImGui/imgui.h"
#include "../Window/PlatformWindow.hpp"
#pragma warning (pop)

enum EditorMode
{
	OBJMODIFIER,
	OBJCREATOR,
	BACKGCREATOR
};

class Object;
struct Background;
class MyImGui
{
public:
	void Init(GLFWwindow* window);
	void Update();
	void End();


	void SetFpsAmount(float amount) { fps = amount; }
private:
	void ObjectList();
	void ObjectModifier();
	void ObjectCreator();

	void BackgroundList();
	void BackgroundCreator();
	void BackgroundtTypeList(Background* target_);

	void LevelEditor();

	void MouseInputEvent();
	void ObjectTypeList(Object* object);
	void DrawTypeList(Object* object);

	void EnemyspawnerKindList(Object* object);

	void SpriteList(Object* object);
	void SpriteList(Background* back);
	void SaveLevelData();
	//test
	bool show_demo_window = true; 
	Object* target = nullptr;
	Object* newObject = nullptr;
	std::string newObjectName = "";

	float  spawnDelayMaxAmount = 0.f;
	float  spawnDelayIncreasedAmount = 0.f;
	int  spawnAmountMaxAmount = 0;
	int eKindsAmount = 0;
	vec2<float> offsetSpawn = 0.f;
	vec2<float> offsetStop = 0.f;
	bool reverseFlag = false;

	Background* targetBackground;
	std::string backgroundGroup = "";

	bool targetIsClicked = false;
	bool mouseIsClickedWithoutObject = false;
	 
	EditorMode editMode = EditorMode::OBJMODIFIER;
	float fps = 0.f;
	//
};
