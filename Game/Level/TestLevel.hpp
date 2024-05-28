#pragma once
#include "Level.hpp"

class TestLevel : public Level
{
public:
	TestLevel() = default;
	~TestLevel() {};

	void Init() override;
	void Update(float dt) override;
	void Restart() override;
	void End() override;

private:
};