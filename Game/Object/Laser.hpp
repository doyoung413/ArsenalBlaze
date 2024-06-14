#pragma once
#include "Object.hpp"

class Laser : public Object
{
public:
	Laser() = default;
	Laser(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Laser() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* obj) override;

	void SetDamage(float amount) { damage = amount;}
	float GetDamage() {return damage;}
	void SetDistance(float x, float y) { distance = { x,y }; }

	void MakeHitParticle(glm::vec2 pos);
protected:
	bool SetTarget();

	glm::vec2 distance = { 0.f,0.f };
	float lastLength = 0.f;

	std::map<int, float> distancesFromTargets;
	float targetY = 0.f;
	float damage = 0.25f;

	float delay = 0.f;
};