#include "EnemyMissile.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"
#include "Component/EnemyAttack.hpp"

EnemyMissile::EnemyMissile(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::ENEMYMISSILE;
	AddComponent<Physics>();
}

void EnemyMissile::Init()
{

}

void EnemyMissile::Update(float dt)
{
	if (isInvincible == true)
	{
		invincibleDelay += 0.5f;
		if (invincibleDelay >= maxInvincibleDelay)
		{
			invincibleDelay = 0.f;
			isInvincible = false;
		}
	}

	delay += 0.1f * dt;
	if (delay > 0.25f)
	{
		delay = 0.f;
		Instance::GetParticleManager()->AddSingleParticle(position, { 8.f, 8.f }, {0.f, 0.f}, 0.f, 20.f, {1.f, 1.f, 1.f, 1.f}, ANIMESPRI, "HMissileE0", 0.47f);
		//앵글에 따른 포지션 이동 필요
	}

	Object::Update(dt);
	GetComponent<Physics>()->Update(dt);
	position.x += speed.x * dt;
	position.y += speed.y * dt;

	if (isOutOfCamera())
	{
		Instance::GetObjectManager()->Destroy(id);
	}

	if (hp <= 0)
	{
		SetColor({ 1.f,0.f,0.f,1.f });
		//Instance::GetParticleManager()->AddSingleParticle(position, { 44.f, 44.f }, { 0.f, 0.f }, 0.f, 15.f, { 1.f, 1.f, 1.f, 1.f }, ANIMESPRI, "enemyExplosionS", 0.5f);
		int amount = 15;
		for (int i = 0; i < amount; i++)
		{
			float colorG = static_cast<float>(rand() % (9 - 3 + 1) + 3) * 0.1f;
			float pSize = static_cast<float>(rand() % (3 - 1 + 1) + (1));

			glm::vec2 newVel = { static_cast<float>(rand() % (5 - (-5) + 1) + (-5)) , (static_cast<float>(rand() % ((5) - (-5) + 1) + (-5))) };
			float lifeTime = static_cast<float>(rand() % (30 - 15 + 1) + 15);
			Instance::GetParticleManager()->AddSingleParticle(position, { pSize, pSize }, newVel, 0.f, lifeTime, { 1.f, colorG, 0.f,1.f }, ParticleType::REC, "", 0.5f);

		}
		//Game::Instance().AddScore(score);
		Instance::GetObjectManager()->Destroy(id);
	}
}

void EnemyMissile::SetAngleToTarget(Object* target)
{
	if (target != nullptr)
	{
		float dx = target->GetPosition().x - position.x;
		float dy = target->GetPosition().y - position.y;

		int angleToTarget = static_cast<int>(atan2(dy, dx) * -60.f);

		angle = static_cast<float>(angleToTarget);
	}
	else
	{
		angle = 90.f;
	}
}
