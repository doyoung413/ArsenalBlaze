#include "TestLevel.hpp"
#include "Instance.hpp"

#include "Component/Physics.hpp"

#include "Object/Player.hpp"
#include "Object/Enemy.hpp"
#include "Object/Item.hpp"

#include <iostream>

void TestLevel::Init()
{
	Instance::GetObjectManager()->AddObject<Player>(0.f, -128.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "Player", ObjectType::PLAYER);

	Instance::GetObjectManager()->AddObject<Enemy>(128.f, 128.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "0", ObjectType::ENEMY);
	static_cast<Enemy*>(Instance::GetObjectManager()->GetLastObject())->SetHp(3);
	static_cast<Enemy*>(Instance::GetObjectManager()->GetLastObject())->SetMaxHp(3);
	Instance::GetObjectManager()->AddObject<Enemy>(-128.f, 128.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "0", ObjectType::ENEMY);
	static_cast<Enemy*>(Instance::GetObjectManager()->GetLastObject())->SetHp(6);
	static_cast<Enemy*>(Instance::GetObjectManager()->GetLastObject())->SetMaxHp(6);

	Instance::GetObjectManager()->AddObject<Item>(-128.f, 128.f, 0.f, 0.f, 32.f, 32.f, DrawType::RECTANGLE, "0", ObjectType::ITEM);
}

void TestLevel::Update(float /*dt*/)
{
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

