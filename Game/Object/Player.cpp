/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Player.cpp
//Description: Source file for player's object class
/*-------------------------------------------------------*/
#include "Player.hpp"
#include "Component/Physics.hpp"
#include "Component/PlayerComponent.hpp"

#include "Object/Enemy.hpp"
#include "Object/EnemyBullet.hpp"
#include "Object/Item.hpp"

#include <iostream>

#include "Instance.hpp"

Player::Player(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::PLAYER;
	AddComponent<Physics>();
	GetComponent<Physics>()->SetAcceleration({ 1.f, 1.f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 6.5f, 6.5f });
	GetComponent<Physics>()->Init({ width, height });

	AddComponent<PlayerComponent>();
}

void Player::Init()
{
}

void Player::Update(float dt)
{
	Object::Update(dt);
}

void Player::End()
{
}

void Player::CollideObject(Object* obj)
{
	switch (obj->GetObjectType())
	{
	case ObjectType::ENEMYBULLET:
		if (GetComponent<PlayerComponent>()->GetInvincibleState() == false && GetComponent<Physics>()->CheckCollision(*obj) == true)
		{
			GetComponent<PlayerComponent>()->SetInvincibleState(true);
			if (static_cast<EnemyBullet*>(obj)->GetIsBreakableToHit() == true)
			{
				Instance::GetObjectManager()->Destroy(obj->GetId());
			}
		}
		break;
	case ObjectType::ENEMY:
		if (GetComponent<PlayerComponent>()->GetInvincibleState() == false && GetComponent<Physics>()->CheckCollision(*obj) == true &&
			static_cast<Enemy*>(obj)->GetIsGround() == false && static_cast<Enemy*>(obj)->GetInvincibleState() == false)
		{
			GetComponent<PlayerComponent>()->SetInvincibleState(true);
			if (static_cast<Enemy*>(obj)->GetMaxHp() <= 5)
			{
				static_cast<Enemy*>(obj)->SetHp((-3));
			}
			static_cast<Enemy*>(obj)->SetIsHit(true);
		}
		break;
	case ObjectType::ITEM:
		if (GetComponent<Physics>()->CheckCollision(*obj) == true)
		{
			switch (static_cast<Item*>(obj)->GetCurrentItemType())
			{
			case ItemType::N:
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::VALCAN);
				break;
			case ItemType::H:
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::HOMING);
				break;
			case ItemType::L:
				Instance::GetGameManager()->SetPlayerWeapon(PlayerWeapon::LASER);
				break;
			}

			Instance::GetObjectManager()->Destroy(obj->GetId());
		}
		break;
	}
}