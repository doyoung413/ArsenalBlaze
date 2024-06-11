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
	if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
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

void PlayerComponent::Attack()
{
	if (isShotReady == true)
	{
		//Instance::GetObjectManager()->AddObject<Bullet>(GetOwner()->GetPosition().x, GetOwner()->GetPosition().y, 0.f, 20.f, 8.f, 12.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		Instance::GetObjectManager()->AddObject<Homing>(GetOwner()->GetPosition().x, GetOwner()->GetPosition().y, 0.f, 20.f, 12.f, 8.f, DrawType::RECTANGLE, "Bullet", ObjectType::BULLET);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetRotate(90.f);
		//Instance::GetObjectManager()->AddObject<Laser>(GetOwner()->GetPosition().x, GetOwner()->GetPosition().y, 0.f, 20.f, 12.f, 12.f, DrawType::RECTANGLE, "Bullet", ObjectType::LASER);
		Instance::GetObjectManager()->GetObjectMap().at(Instance::GetObjectManager()->GetLastObjectID())->SetDepth(0.48f);
		isShotReady = false;
	}
}

void PlayerComponent::Delay(float dt)
{
	if (isShotReady == false)
	{
		shotDelay +=  dt;
		if (shotDelay >= 80.f)
		{
			shotDelay = 0.f;
			isShotReady = true;
		}
	}
}
