#pragma once
#include "Object.hpp"

class Barrier : public Object
{
public:
	Barrier() = default;
	Barrier(float positionX, float positionY, float speedX, float speedY, float width, float height,
		DrawType drawType, std::string name, ObjectType objectType);
	~Barrier() { player = nullptr; };

	void Init() override {};
	void Init(Object* player_, float angleIncrease_);
	void Update(float dt) override;

protected:
	void SetPlayer(Object* player_) { player = player_; }
	void SetAngleIncrease(float amount) { angleIncrease = amount; }

	glm::vec2 distanceMax = { 0.f,0.f };
	float positionAngle = 0.f;
	float angleIncrease = 0.f;
	float distanceIncrease = 0.f;

	Object* player = nullptr;
	bool isReady = false;
};