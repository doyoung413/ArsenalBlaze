#include "Item.hpp"
#include "Instance.hpp"
#include "Component/Physics.hpp"

Item::Item(float positionX, float positionY, float speedX, float speedY, float width,
	float height, DrawType drawType, std::string name, ObjectType objectType)
	: Object(positionX, positionY, speedX, speedY, width, height, drawType, name, objectType)
{
	objectType = ObjectType::ITEM;
	AddComponent<Physics>();
	GetComponent<Physics>()->SetAcceleration({ 3.f, 2.0f });
	GetComponent<Physics>()->SetGravity(0.f);
	GetComponent<Physics>()->SetMaxVelocity({ 6.f, 2.f });

}

void Item::Init()
{
}

void Item::Update(float dt)
{
	Object::Update(dt);
	moveDelay += 0.25f * dt;
	changeDelay += 0.2f * dt;

	if (moveDelay >= 8.f)
	{
		moveDelay = 0.f;
		direction *= -1.f;
	}

	GetComponent<Physics>()->Update(dt);
	GetComponent<Physics>()->Move(direction * 0.2f, -1.0f, dt);

	if (changeDelay >= 8.f)
	{
		changeDelay = 0.f;
		currentItemNumber++;
		if (currentItemNumber > 2)
		{
			currentItemNumber = 1;
		}
	}

	switch (currentItemNumber)
	{
	case 0:
		currentItem = ItemType::N;
		break;
	case 1:
		currentItem = ItemType::H;
		break;
	case 2:
		currentItem = ItemType::L;
		break;
	}

	glm::vec2 windowSize = { static_cast<float>(Instance::GetCameraManager()->GetViewSize().x), static_cast<float>(Instance::GetCameraManager()->GetViewSize().y) };
	glm::vec2 cameraCenter = Instance::GetCameraManager()->GetCenter();

	if (position.y < -(windowSize.y / 2.f) - (size.y * 2.f))
	{
		Instance::GetObjectManager()->Destroy(id);
	}
}
