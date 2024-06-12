/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Enemy.cpp
//Description: Source file for enemy's object class
/*-------------------------------------------------------*/
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"

Enemy::Enemy(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, ObjectType::ENEMY)
{
	AddComponent<Physics>();
	GetComponent<Physics>()->Init({ width, height });

	SetDepth(0.49f);

	viewSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	cameraCenter = Instance::GetCameraManager()->GetCenter();
}

void Enemy::Init()
{

}

void Enemy::Update(float dt)
{
	Hit(dt);
	if (isInCamera == true)
	{
		Object::Update(dt);
		if (isOutOfCamera())
		{
			Instance::GetObjectManager()->Destroy(id);
		}
	}
	else if (isInCamera == false)
	{
		Object::Draw(dt);
		position.y += Instance::GetGameManager()->GetScrollSpeed().y;
		if (isEdgeOfCamera() == true)
		{
			isInCamera = true;
			if (isGround == false)
			{
				position = { spawnPosition + spawnPositionOffset, 0.f };
			}
		}
	}
	Death(dt);
}

void Enemy::CollideObject(Object* obj)
{
	switch (obj->GetObjectType())
	{
	case ObjectType::BULLET:
		if (GetComponent<Physics>()->CheckCollision(*obj) == true)
		{
			static_cast<Bullet*>(obj)->MakeHitParticle();
			Instance::GetObjectManager()->Destroy(obj->GetId());
			if (GetInvincibleState() == false)
			{
				SetIsHit(true);
				SetHp(GetHp() - static_cast<Bullet*>(obj)->GetDamage());
			}
		}
		break;
	}
}

void Enemy::SetAngleToTarget(Object* target)
{
	if (target != nullptr)
	{
		float dx = target->GetPosition().x - position.x;
		float dy = target->GetPosition().y - position.y;

		int angleToTarget = static_cast<int>(atan2(dy, dx) * 60.f);

		angle = static_cast<float>(angleToTarget - (angleToTarget % 5));
	}
}

void Enemy::Hit(float dt)
{
	if (isHit == true)
	{
		if (MaxHp / 3 < hp)
		{
			SetColor({ 0.6f,0.6f,0.6f,1.f });
		}
		else if (MaxHp / 3 >= hp)
		{
			SetColor({ 1.f,0.f,0.f,1.f });
		}

		invincibleDelay += dt;
		if (invincibleDelay >= 3.f)
		{
			SetColor({ 1.f,1.f,1.f,1.f });
			invincibleDelay = 0.f;
			isHit = false;
		}
	}
}

void Enemy::Death(float /*dt*/)
{
	if (hp <= 0)
	{
		SetColor({ 1.f,0.f,0.f,1.f });
		int amount = 15;
		for (int i = 0; i < amount; i++)
		{
			float colorG = static_cast<float>(rand() % (9 - 3 + 1) + 3) * 0.1f;
			float pSize = static_cast<float>(rand() % (3 - 1 + 1) + (1));

			glm::vec2 newVel = { static_cast<float>(rand() % (5 - (-5) + 1) + (-5)) , (static_cast<float>(rand() % ((5) - (-5) + 1) + (-5))) };
			float lifeTime = static_cast<float>(rand() % (30 - 15 + 1) + 15);
			Instance::GetParticleManager()->AddSingleParticle({ position.x, position.y }, { pSize, pSize }, newVel, 0.f, lifeTime, { 1.f, colorG, 0.f,1.f }, ParticleType::REC, "", 0.5f);

		}
		Instance::GetObjectManager()->Destroy(id);
	}
}
