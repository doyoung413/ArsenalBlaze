#pragma once
#include "Object.hpp"
#include <map>

class Homing : public Object
{
public:
	Homing() = default;
	Homing(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Homing() { target = nullptr; }

	void Init() override;
	void Update(float dt) override;
	void SetTarget();
	bool IsTargetNULL();

	bool IsSerach(Object* target_);

	void SetDamage(float amount) { damage = amount;}
	float GetDamage() {return damage;}
	
protected:
	float damage = 0;

	float searchRadius = 200.f; 
	glm::vec2 prevSpeed{ 0.f,0.f };

	Object* target = nullptr;
	bool isLockOn = false;
	bool isLockReady = false;
	bool isInCamera = false;
	int targetID = -1;

	float delay = 0.f;

	std::map<int, float> distancesFromTargets;
};