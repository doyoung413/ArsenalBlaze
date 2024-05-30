/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Player.hpp
//Description: Header file for player's object class
/*-------------------------------------------------------*/
#pragma once
#include "Object.hpp"

class Player : public Object
{
public:
    Player() = default;
	Player(float positionX, float positionY, float speedX, float speedY, float width, float height,
           DrawType drawType, std::string name, ObjectType objectType);
	~Player() { End(); }

	void Init() override;
	void Update(float dt) override;
	void End();
	void CollideObject(Object* obj) override;
private:
};