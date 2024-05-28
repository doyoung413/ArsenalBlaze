/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Physics.hpp
//Description: Header file for component which object physics & collide
/*-------------------------------------------------------*/
#pragma once
#include "Component.hpp"
#include "glm.hpp"

#include <math.h>
#include <vector>

constexpr float PI = 3.1415926535897932384626433832795f;
constexpr float TWOPI = 2.f * PI;
constexpr float HALFPI = PI / 2.f;
constexpr float DegreeToRadian(float angleInDegree) { return angleInDegree * (PI / 180.0f); }

class Object;
struct AABB
{
	glm::vec2 min = { 0.f,0.f };
	glm::vec2 max = { 0.f,0.f };
	glm::vec2 collisionBoxSize{ 0.f, 0.f };
	glm::vec2 collisionBoxPosition{ 0.f,0.f };
};

class Physics : public Component
{
public:
	Physics() : Component(ComponentTypes::PHYSICS) {}
	~Physics() override {};

	void Init() override {};
	void Init(glm::vec2 aabbSize);
    void Update(float dt) override;
	void Update(float dt, glm::vec2& pos);
    void End() override {};
	
	void Move(const float dirX, const float dirY, float dt);
	void Jump(const float force);
	void Gravity(float dt);

	bool CheckCollision(Object& obj);

	glm::vec2 PointPlusVector(glm::vec2 point, glm::vec2 vector);
	glm::vec2 VectorPlusVector(glm::vec2 v0, glm::vec2 v1);

	glm::vec2 VectorNormalize(glm::vec2 v);
	float VectorLength(glm::vec2 v);

	glm::vec2 GetVelocity() {return velocity;}
	AABB GetAABB() { return aabb; }
	void SetCollisionBoxPosition(float x, float y) { aabb.collisionBoxPosition = glm::vec2{ x, y }; }
	void SetCollisionBoxSize(float width, float height) { aabb.collisionBoxSize = glm::vec2{ width, height }; }

	void SetVelocityX(float v) { velocity.x = v; }
	void SetVelocityY (float v) {velocity.y = v;}
	void SetMinVelocity (glm::vec2 v) {velocityMin = v;}
	void SetMaxVelocity (glm::vec2 v) {velocityMax = v;}
	void SetAcceleration(glm::vec2 v){acceleration = v;};
	void SetFriction(float f) {friction = f;}
	void SetGravity(float g) {gravity = g;}
private:
	glm::vec2 velocity = {0.0f, 0.0f};
	glm::vec2 velocityMin = {0.f, 0.f};
	glm::vec2 velocityMax = {10.f, 10.f};
	glm::vec2 acceleration = {0.f, 0.f};

	float friction = 0.9f;
	float gravity = 0.f;
	float deltaTime = 0.f;

	AABB aabb;

	glm::vec2 RotatePoint(AABB aabb_, const glm::vec2& point, float angle);
	bool IsSeparatingAxis(const glm::vec2& axis, const std::vector<glm::vec2>& points1, const std::vector<glm::vec2>& points2);
	void SetMinMax();
};