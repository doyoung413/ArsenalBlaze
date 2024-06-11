#pragma once
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

private:
};