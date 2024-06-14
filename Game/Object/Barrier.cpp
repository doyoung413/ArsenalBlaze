#include "Barrier.hpp"
#include "Instance.hpp"

Barrier::Barrier(float positionX, float positionY, float speedX, float speedY, float width, float height, DrawType drawType, std::string name, ObjectType objectType)
: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::BARRIER;
	distanceMax.x = positionX;
	distanceMax.y = positionY;
	depth = 0.f;
}

void Barrier::Init(Object* player_, float angleIncrease_)
{
	SetPlayer(player_);
	SetAngleIncrease(angleIncrease_);
	position = { player_->GetPosition().x, player_->GetPosition().y, 0.f };
}

void Barrier::Update(float dt)
{
	Object::Update(dt);
	if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().KEY1) == false && isReady == true)
	{
		if (player != nullptr)
		{
			float dx = player->GetPosition().x + ((distanceMax.x) * cos(positionAngle)) - ((distanceMax.y) * sin(positionAngle)) * dt;
			float dy = player->GetPosition().y + ((distanceMax.x) * sin(positionAngle)) + ((distanceMax.y) * cos(positionAngle)) * dt;

			positionAngle += angleIncrease * dt;

			position = { dx, dy, 0.f };
		}
		else
		{
		}
	}
	else if (Instance::GetInputManager()->IsKeyPressed(Instance::GetGameManager()->GetKeySetting().KEY1) == true && isReady == true)
	{
		if (player != nullptr)
		{
			float dx = player->GetPosition().x + ((distanceMax.x) * cos(positionAngle)) - ((distanceMax.y) * sin(positionAngle));
			float dy = player->GetPosition().y + ((distanceMax.x) * sin(positionAngle)) + ((distanceMax.y) * cos(positionAngle));

			position = { dx, dy, 0.f };
		}
	}
	else if (isReady == false)
	{
		if (distanceMax.x > 0.f)
		{
			distanceIncrease += 2.5f * dt;
			position = { player->GetPosition().x + distanceIncrease, player->GetPosition().y, 0.f };
			if (position.x >= distanceMax.x + player->GetPosition().x)
			{
				isReady = true;
			}
		}
		else if (distanceMax.x < 0.f)
		{
			distanceIncrease -= 2.5f * dt;
			position = { player->GetPosition().x + distanceIncrease, player->GetPosition().y, 0.f };
			if (position.x <= distanceMax.x + player->GetPosition().x)
			{
				isReady = true;
			}

		}

	}
}
