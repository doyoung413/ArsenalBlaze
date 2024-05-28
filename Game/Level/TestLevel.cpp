#include "TestLevel.hpp"
#include "Instance.hpp"

#include "Component/TestComp.hpp"

#include <iostream>

void TestLevel::Init()
{
	Instance::GetObjectManager()->AddObject<Object>(0.f, 0.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE);
	Instance::GetObjectManager()->GetLastObject()->AddComponent<TestComp>();
	Instance::GetObjectManager()->GetLastObject()->SetColor({ 0.f,1.f,0.f,1.f });
}

void TestLevel::Update(float /*dt*/)
{
	if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
	{
		std::cout << Instance::GetInputManager()->KeyBoardToString(Instance::GetInputManager()->GetPressKey()) << std::endl;
	}
}

void TestLevel::Restart()
{
	End();
	Init();
}

void TestLevel::End()
{
	Instance::GetCameraManager()->Reset();
	Instance::GetObjectManager()->DestroyAllObjects();
}

