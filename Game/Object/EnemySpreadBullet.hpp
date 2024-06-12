/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: EnemySpreadBullet.hpp
//Description: Header file for enemy's bullet object class
/*-------------------------------------------------------*/
#pragma once
#include "EnemyBullet.hpp"

class EnemySpreadBullet : public EnemyBullet
{
public:
	EnemySpreadBullet() = default;
	EnemySpreadBullet(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, float shotDelayMax = 1.f, int numBullets_ = 8, float spreadBulletSpeed_ = 1.f);
	~EnemySpreadBullet() {};

	void Init() override;
	void Update(float dt) override;
protected:
	float delay = 0.f;
	float delayMax = 0.f;
	float spreadBulletSpeed = 1.f;
	int numBullets = 0;
};