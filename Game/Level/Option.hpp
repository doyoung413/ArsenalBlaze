#pragma once
#include "Text/Text.hpp"
#include "Instance.hpp"
#include "Level.hpp"

class Option : public Level
{
public:
	Option() = default;
	~Option() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;
	void Input();

private:
	void KeyChanging(int index_, float dt);
	void SoundTestMod() {};

	Text text;
	glm::vec2 textCursor = { 0.f,0.f };
	int currentSoundChannel = 0;

	int index = 0;
	int bgmIndex = 0;
	int seIndex = 0;

	float changeDelay = 0.f;
	bool isKeySetting = false;
	bool isSelected = false;

	SpriteManager* spriteManager = nullptr;
	GameManager* gameManager = nullptr;
	InputManager* inputManager = nullptr;
	SoundManager* soundManager = nullptr;
};