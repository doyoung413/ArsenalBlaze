#include "Homing.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"

#include <iostream>
#include <cmath>

Homing::Homing(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::BULLET;

	AddComponent<Physics>();
	GetComponent<Physics>()->SetAcceleration({ 1.0f, 1.f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 10.0f, 10.0f });
	Init();
}

void Homing::Init()
{
}

void Homing::Update(float dt)
{
	Object::Update(dt);

	if (isLockReady == true)
	{
		if ((isOutOfCamera() && isInCamera == true) || isOutOfWindowHigh() == true)
		{
			Instance::GetObjectManager()->Destroy(id);
		}
		if (isInOfCamera())
		{
			isInCamera = true;
		}

		if (isLockOn == true && IsTargetNULL() == true)
		{
			if (angle != 270.f)
			{
				SetRotate(angle);
				position.x += prevSpeed.x * dt;
				position.y += prevSpeed.y * dt;
			}
			else
			{
				SetRotate(270.f);
				GetComponent<Physics>()->Move(0.f, speed.y, dt);
			}
		}
		else if (isLockOn == true && IsTargetNULL() == false)
		{
			std::cout << speed.x << std::endl;
			float targetX = target->GetPosition().x;
			float targetY = target->GetPosition().y;

			float dx = targetX - position.x;
			float dy = targetY - position.y;

			int angleToTarget = static_cast<int>(atan2(dy, dx) * -60.f);
			int leftAngle = (angleToTarget % 15);
			int tempAngle = angleToTarget - leftAngle;

			if (tempAngle < 0)
			{
				tempAngle += 360;
			}

			if (tempAngle != angle)
			{
				if (tempAngle < angle)
				{
					if (tempAngle == 0)
					{
						SetRotate(0.f);
					}
					else
					{
						SetRotate(std::clamp(GetRotate() - 15.f, 0.f, 360.f));
					}
				}
				else if (tempAngle > angle)
				{
					if (tempAngle == 345)
					{
						SetRotate(345.f);
					}
					else
					{
						SetRotate(std::clamp(GetRotate() + 15.f, 0.f, 360.f));
					}
				}
			}

			float moveAngle = static_cast<float>(angle) / -60.f;
			if (moveAngle > 3.f)
			{
				moveAngle = -(moveAngle)+3.f;
			}
			prevSpeed = { cos(moveAngle) * speed.x, sin(moveAngle) * speed.y };

			position.x += prevSpeed.x * dt;
			position.y += prevSpeed.y * dt;
		}
		else if (isLockOn == false)
		{
			GetComponent<Physics>()->Move(speed.x, speed.y, dt);
			SetTarget();
		}
	}
	else
	{
		GetComponent<Physics>()->Move(speed.x, speed.y, dt);
		delay += dt;
		if (delay > 0.f)
		{
			delay = 0.f;
			isLockReady = true;
		}
	}
}

bool Homing::IsSerach(Object* target_)
{
	glm::vec2 distance = { abs(position.x - target_->GetPosition().x) - target_->GetSize().x,
		abs(position.y - target_->GetPosition().y) - target_->GetSize().y };

	if (distance.x > searchRadius || distance.y > searchRadius) { return false; }
	if (distance.x <= 0 || distance.y <= 0) { return true; }

	return (distance.x * distance.x + distance.y * distance.y <= searchRadius * searchRadius);
}

void Homing::SetTarget()
{
	for (auto& obj : Instance::GetObjectManager()->GetObjectMap())
	{
		if (obj.second.get()->GetObjectType() == ObjectType::ENEMY &&
			IsSerach(obj.second.get()))
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
			return a.second > b.second;
		});
		if (Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get() != nullptr)
		{
			target = Instance::GetObjectManager()->GetObjectMap().at(vec.begin()->first).get();
			targetID = vec.begin()->first;
			isLockOn = true;
			speed = { 13.f,13.f, 0.f };
		}
		distancesFromTargets.clear();
	}
}

bool Homing::IsTargetNULL()
{
	auto entry = Instance::GetObjectManager()->GetObjectMap().find(targetID);
	if (entry == Instance::GetObjectManager()->GetObjectMap().end())
	{
		return true;
	}
	return false;
}
