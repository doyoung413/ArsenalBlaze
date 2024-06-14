#pragma once
#include "Level.hpp"
#include "Instance.hpp"

#ifdef _DEBUG
#include "MapEditor.hpp"
#endif

class Stage1 : public Level
{
public:
	Stage1() = default;
	~Stage1() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;

private:
	GameManager* gameManager = nullptr;
	ObjectManager* objectManager = nullptr;
	CameraManager* cameraManager = nullptr;
	BackgroundManager* backgroundManager = nullptr;
	SoundManager* soundManager = nullptr;
#ifdef _DEBUG
	MapEditor mapEditor;
#endif
};