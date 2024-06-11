#include "Laser.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"
#include "Object/Enemy.hpp"

Laser::Laser(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::LASER;
	AddComponent<Physics>();
	SetDepth(0.6f);

	GetComponent<Physics>()->SetCollisionBoxSize(13.f, 400.f);
	GetComponent<Physics>()->SetCollisionBoxPosition(0.f, 400.f);

	if (Instance::GetObjectManager()->FindObjectWithName("Player") != nullptr)
	{
		glm::vec2 playerP = Instance::GetObjectManager()->FindObjectWithName("Player")->GetPosition();
		position.x = playerP.x + distance.x;
		position.y = playerP.y + distance.y;
	}
}

void Laser::Init()
{
}

void Laser::Update(float dt)
{
	Object::Update(dt);

	if (delay > 40.f || Instance::GetObjectManager()->FindObjectWithName("Player") == nullptr)
	{
			Instance::GetObjectManager()->Destroy(id);
	}
	else
	{
		delay += dt;
		if (SetTarget())
		{
			float distanceTtoP = targetY - position.y;
			Instance::GetSpriteManager()->DrawRectangle({ position.x, position.y + distanceTtoP / 2.f, 0.f }, 0.f, { 13.f, distanceTtoP / 2.f , 0.f }, { 1.f, 1.f,1.f,0.5f }, depth);
			lastLength = distanceTtoP / 2.f;
			Instance::GetSpriteManager()->DrawRectangle({ position.x ,targetY, 0.f }, 0.f, { 24.f, 16.f, 0.f }, { 1.f, 1.f,1.f,1.f }, depth + 0.01f);
		}
		else
		{
			Instance::GetSpriteManager()->DrawRectangle({ position.x, position.y + 400.f, 0.f }, 0.f, { 13.f,400.f, 0.f }, { 1.f, 1.f,1.f,0.5f }, depth);
			lastLength = 400.f;
		}
	}

	if (Instance::GetObjectManager()->FindObjectWithName("Player") != nullptr)
	{
		glm::vec2 playerP = Instance::GetObjectManager()->FindObjectWithName("Player")->GetPosition();
		position.x = playerP.x + distance.x;
		position.y = playerP.y + distance.y;
	}
}

void Laser::CollideObject(Object* /*obj*/)
{
}

void Laser::MakeHitParticle(glm::vec2 /*pos*/)
{
}

bool Laser::SetTarget()
{
	for (auto& obj : Instance::GetObjectManager()->GetObjectMap())
	{
		if (obj.second.get()->GetObjectType() == ObjectType::ENEMY &&
			GetComponent<Physics>()->CheckCollision(*obj.second.get()) &&  position.y <= obj.second.get()->GetPosition().y)
		{
			float deltaX = obj.second.get()->GetPosition().x - position.x;
			float deltaY = obj.second.get()->GetPosition().y - position.y;

			distancesFromTargets.emplace(obj.second.get()->GetId(), (deltaX * deltaX) + (deltaY * deltaY));
		}
	}

	if (!distancesFromTargets.empty())
	{
		std::vector<std::pair<int, float>> vec(distancesFromTargets.begin(), distancesFromTargets.end());
		std::sort(vec.begin(), vec.end(), [](std::pair<int, float> a, std::pair<int, float> b)
		{
			return a.second < b.second;
		});

		if (Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get() != nullptr)
		{
			if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
			{
				if (static_cast<Enemy*>(Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get())->GetInvincibleState() == false &&
					static_cast<Enemy*>(Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get())->isInOfCamera() == true)
				{
					MakeHitParticle({ GetPosition().x, Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get()->GetPosition().y });
					static_cast<Enemy*>(Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get())->SetIsHit(true);
					static_cast<Enemy*>(Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get())
						->SetHp(static_cast<Enemy*>(Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get())->GetHp() - GetDamage());
				}
			}
			targetY = Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get()->GetPosition().y;
			distancesFromTargets.clear();
			return true;
		}
		else
		{
			targetY = 0.f;
			distancesFromTargets.clear();
			return false;
		}
	}
	return false;
}
