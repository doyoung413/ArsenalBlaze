#pragma once
#include "Text/Text.hpp"
#include "Instance.hpp"
#include "Level.hpp"

class Title : public Level
{
public:
	Title() = default;
	~Title() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;
	void Input();

private:
	Text text;

	int index = 0;
	bool isSelected = false;
};