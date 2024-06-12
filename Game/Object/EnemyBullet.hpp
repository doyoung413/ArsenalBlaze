/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemyBullet.hpp
//Description: Header file for enemy's bullet object class
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"

class EnemyBullet : public Object
{
public:
	EnemyBullet() = default;
	EnemyBullet(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name);
	~EnemyBullet() {};

	void Init() override;
	void Update(float dt) override;

	void SetDamage(int amount) { damage = amount;}
	int GetDamage() {return damage;}

	void SetIsBreakableToHit(bool state) { isBreakableToHit = state; }
	bool GetIsBreakableToHit() { return isBreakableToHit; }
protected:
	int damage = 5;
	bool isBreakableToHit = true;
};