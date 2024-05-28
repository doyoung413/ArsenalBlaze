#include "TestComp.hpp"
#include "Instance.hpp"

void TestComp::Update(float dt)
{
	if (Instance::GetInputManager()->IsKeyPressed(KEYBOARDKEYS::RIGHT))
	{
		GetOwner()->SetXPosition(GetOwner()->GetPosition().x + 1.f * dt);
	}
	if (Instance::GetInputManager()->IsKeyPressed(KEYBOARDKEYS::LEFT))
	{
		GetOwner()->SetXPosition(GetOwner()->GetPosition().x - 1.f * dt);
	}
	if (Instance::GetInputManager()->IsKeyPressed(KEYBOARDKEYS::UP))
	{
		GetOwner()->SetYPosition(GetOwner()->GetPosition().y + 1.f * dt);
	}
	if (Instance::GetInputManager()->IsKeyPressed(KEYBOARDKEYS::DOWN))
	{
		GetOwner()->SetYPosition(GetOwner()->GetPosition().y - 1.f * dt);
	}
}
