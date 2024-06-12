/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: PlayerComponent.cpp
//Description: Source file for component for player
/*-------------------------------------------------------*/
#include "PlayerComponent.hpp"
#include "Object/Bullet.hpp"
#include "Object/Homing.hpp"
#include "Object/Laser.hpp"
#include "Instance.hpp"

PlayerComponent::PlayerComponent() : Component(ComponentTypes::PLAYERCOMP) 
{
}

void PlayerComponent::Init()
{
}

void PlayerComponent::Update(float dt)
{
	windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	cameraCenter = Instance::GetCameraManager()->GetCenter();

	Input(dt);
	Delay(dt);

	if (isInvincible == true)
	{
		invincibleDelay += dt;
		GetOwner()->SetColor({ 1.f,1.f,1.f,0.3f });
		if (invincibleDelay >= 3.f)
		{
			GetOwner()->SetColor({ 1.f,1.f,1.f,1.f });
			invincibleDelay = 0.f;
			isInvincible = false;
		}
	}
}

void PlayerComponent::Input(float dt)
{
	if (Instance::GetLevelManager()->GetGameState() != State::PAUSE && Instance::GetGameManager()->GetIsPlayerCanControl() == true)
	{
		if (isHit == false)
		{
			if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().RIGHT))
			{
				GetOwner()->SetXPosition(GetOwner()->GetPosition().x + playerMoveSpeed * dt);
			}
			else if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().LEFT))
			{
				GetOwner()->SetXPosition(GetOwner()->GetPosition().x - playerMoveSpeed * dt);
			}
			if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().UP))
			{
				GetOwner()->SetYPosition(GetOwner()->GetPosition().y + playerMoveSpeed * dt);
			}
			else if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().DOWN))
			{
				GetOwner()->SetYPosition(GetOwner()->GetPosition().y - playerMoveSpeed * dt);
			}
			if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().KEY1))
			{
				Attack();
			}
		}
	}
}

void PlayerComponent::SetMaxSubShotDelay(float maxDelay)
{
	maxSubShotDelay = maxDelay;
	subShotDelay = 0.f;
	isSubShotReady = false;
}

void PlayerComponent::Attack()
{
	if (isShotReady == true)
	{
		Instance::GetObjectManager()->AddObject<Bullet>(GetOwner()->GetPosition().x + 12.f, GetOwner()->GetPosition().y, 0.f, 15.f, 20.f, 5.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetSpriteName("BulletW");
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);

		Instance::GetObjectManager()->AddObject<Bullet>(GetOwner()->GetPosition().x - 12.f, GetOwner()->GetPosition().y, 0.f, 15.f, 20.f, -5.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetSpriteName("BulletW");
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);

		Instance::GetObjectManager()->AddObject<Bullet>(GetOwner()->GetPosition().x + 12.f, GetOwner()->GetPosition().y, 2.f, 15.f, 17.f, 3.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		static_cast<Bullet*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->SetDamage(static_cast<Bullet*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->GetDamage() / 2.f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetSpriteName("BulletWS");
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(280.f);

		Instance::GetObjectManager()->AddObject<Bullet>(GetOwner()->GetPosition().x - 12.f, GetOwner()->GetPosition().y, -2.f, 15.f, 17.f, -3.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		static_cast<Bullet*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->SetDamage(static_cast<Bullet*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->GetDamage() / 2.f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetSpriteName("BulletWS");
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(260.f);
		isShotReady = false;
	}
}

void PlayerComponent::SubAttack()
{
	if (isSubShotReady == true)
	{
		switch (Instance::GetGameManager()->GetPlayerWeapon())
		{
		case PlayerWeapon::HOMING:
			switch (static_cast<int>(Instance::GetGameManager()->GetWeaponPower().homing))
			{
			case 0:
				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x + 16.f, GetOwner()->GetPosition().y - 32.f, 2.f, 10.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);
				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x - 16.f, GetOwner()->GetPosition().y - 32.f, -2.f, 10.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);
				break;
			case 1:
				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x + 16.f, GetOwner()->GetPosition().y - 32.f, 2.f, 10.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);
				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x - 16.f, GetOwner()->GetPosition().y - 32.f, -2.f, 10.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);


				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x + 16.f, GetOwner()->GetPosition().y - 32.f, 0.125f, 2.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);
				Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x - 16.f, GetOwner()->GetPosition().y - 32.f, -0.125f, 2.f, 16.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(270.f);
				break;
			}
			break;
		case PlayerWeapon::LASER:
			switch (static_cast<int>(Instance::GetGameManager()->GetWeaponPower().laser))
			{
			case 0:
				Instance::GetObjectManager()->AddObject<Laser>(GetOwner()->GetPosition().x, GetOwner()->GetPosition().y + 26.f, 0.f, 0.f, 13.f, 13.f, DrawType::SPRITEANIMATION, "Laser", ObjectType::LASER);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.7f);
				static_cast<Laser*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->SetDistance(0, 26.f);
				break;
			case 1:
				Instance::GetObjectManager()->AddObject<Laser>(GetOwner()->GetPosition().x + 26.f, GetOwner()->GetPosition().y + 26.f, 0.f, 0.f, 13.f, 13.f, DrawType::SPRITEANIMATION, "Laser", ObjectType::LASER);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.7f);
				static_cast<Laser*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->SetDistance(26.f, 26.f);

				Instance::GetObjectManager()->AddObject<Laser>(GetOwner()->GetPosition().x - 26.f, GetOwner()->GetPosition().y + 26.f, 0.f, 0.f, 13.f, 13.f, DrawType::SPRITEANIMATION, "Laser", ObjectType::LASER);
				Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.7f);
				static_cast<Laser*>(Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID()).get())->SetDistance(-26.f, 26.f);
				break;
			}
		}
		isSubShotReady = false;
	}
}

void PlayerComponent::Delay(float dt)
{
	if (isShotReady == false)
	{
		shotDelay +=  dt;
		if (shotDelay >= maxShotDelay)
		{
			shotDelay = 0.f;
			isShotReady = true;
		}
	}
	if (isSubShotReady == false)
	{
		subShotDelay += dt;
		if (subShotDelay >= maxSubShotDelay)
		{
			subShotDelay = 0.f;
			isSubShotReady = true;
		}
	}
}
