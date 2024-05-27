#pragma once
#include "Component.hpp"

class TestComp : public Component
{
public:
	TestComp() : Component(ComponentTypes::TEST) {}
	~TestComp() override {};

	void Init() override {};
	void Update(float dt) override;
	void End() override {};
};