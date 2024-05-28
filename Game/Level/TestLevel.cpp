#include "TestLevel.hpp"
#include "Instance.hpp"

#include "Component/TestComp.hpp"
#include "Component/Physics.hpp"

#include <iostream>

void TestLevel::Init()
{
	Instance::GetObjectManager()->AddObject<Object>(0.f, 0.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE);
	Instance::GetObjectManager()->GetLastObject()->AddComponent<TestComp>();
	Instance::GetObjectManager()->GetLastObject()->AddComponent<Physics>();
	Instance::GetObjectManager()->GetLastObject()->GetComponent<Physics>()->Init({ 32.f, 32.f });


	Instance::GetObjectManager()->AddObject<Object>(128.f, 128.f, 0.f, 0.f, 16.f, 16.f, DrawType::RECTANGLE);
	Instance::GetObjectManager()->GetLastObject()->AddComponent<Physics>();
	Instance::GetObjectManager()->GetLastObject()->GetComponent<Physics>()->Init({ 16.f, 16.f });
}

void TestLevel::Update(float dt)
{
	Instance::GetObjectManager()->GetLastObject()->SetRotate(Instance::GetObjectManager()->GetLastObject()->GetRotate() + 0.05f * dt);
	if (Instance::GetInputManager()->GetPressKey() != KEYBOARDKEYS::UNKNOWN)
	{
		std::cout << Instance::GetInputManager()->KeyBoardToString(Instance::GetInputManager()->GetPressKey()) << std::endl;
	}
	if (Instance::GetObjectManager()->FindObjectWithId(0)->GetComponent<Physics>()->CheckCollision(*Instance::GetObjectManager()->FindObjectWithId(1)) == true)
	{
		std::cout << "Collide!" << std::endl;
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

