#pragma once
#include "../Shader/Shader.hpp"


class Animation
{
public:
	Animation() = default;

	void Initialize(int column, int row, float speed, const Shader shader, bool loop, bool isPaused = false);
	void Animate(float dt);
	void ChangeAnimation(int column, int row);
	void ChangeAnimation(int column, int row, float speed);

	void SetAnimationReverse(bool state);
	void ChangeSpeed(float speed) { animateSpeed = speed; }
	void InitializeAnimation();

	int GetFrameIndexX() { return frameX; }
	int GetFrameIndex() { return frameIndex; }
	Shader GetShader() { return animationShader; }
	bool isAnimationEnd();

	void SetFrameIndex(int index) { baseTime = static_cast<float>(index);
	frameIndex = static_cast<int>(baseTime) % (frameX * frameY);}
	void TogglePause() { isAnimationPause = !isAnimationPause; }
private:
	Shader animationShader;

	int frameX = 0;
	int frameY = 0;
	float animateSpeed = 0.f;
	bool animationLoop = true;
	bool isAnimationPause = false;
	bool isReverse = false;
	
	int frameIndex = 0;
	int prevIndex = 0;
	float baseTime = 0.0f;
};
