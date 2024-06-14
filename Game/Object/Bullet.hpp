/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Bullet.hpp
//Description: Header file for player's bullet object class
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"

class Bullet : public Object
{
public:
    Bullet() = default;
	Bullet(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Bullet() {};

	void Init() override;
	void Update(float dt) override;
	void CollideObject(Object* /*obj*/) override {};

	void SetDamage(float amount) { damage = amount;}
	float GetDamage() {return damage;}
	
	void MakeHitParticle() {};
protected:
	float damage = 0.5f;

	glm::vec2 prePos = { 0.f, 0.f };
};