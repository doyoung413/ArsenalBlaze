/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Physics.cpp
//Description: Source file for component which object physics & collide
/*-------------------------------------------------------*/
#include "Physics.hpp"
#include "Instance.hpp"

#include <iostream>

void Physics::Init(glm::vec2 aabbSize)
{
    aabb.collisionBoxSize.x = aabbSize.x;
    aabb.collisionBoxSize.y = aabbSize.y;

    SetMinMax();
}

void Physics::Update (float dt)
{
    if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
    {
        deltaTime = dt;
        velocity.x *= friction;
        velocity.y *= friction;

        if (std::abs(velocity.x) < velocityMin.x)
        {
            velocity.x = 0.f;
        }
        if (std::abs(velocity.y) < velocityMin.y)
        {
            velocity.y = 0.f;
        }

        Component::GetOwner()->SetXPosition(Component::GetOwner()->GetPosition().x + velocity.x);
        Component::GetOwner()->SetYPosition(Component::GetOwner()->GetPosition().y + velocity.y);

        SetMinMax();
#ifdef _DEBUG
        float centerX = aabb.max.x - aabb.collisionBoxSize.x;
        float centerY = aabb.max.y - aabb.collisionBoxSize.y;
        Instance::GetSpriteManager()->DrawRectangleLine({ centerX ,centerY, 0.f}, GetOwner()->GetRotate(), { aabb.collisionBoxSize , 0.f}, {0.f,1.f,0.f,1.f}, 1.f);

#endif
    }
}

void Physics::Update(float dt, glm::vec2& pos)
{
    if (Instance::GetLevelManager()->GetGameState() != State::PAUSE)
    {
        deltaTime = dt;
        velocity.x *= friction;
        velocity.y *= friction;

        if (std::abs(velocity.x) < velocityMin.x)
        {
            velocity.x = 0.f;
        }
        if (std::abs(velocity.y) < velocityMin.y)
        {
            velocity.y = 0.f;
        }

        pos.x += velocity.x;
        pos.y += velocity.y;
    }
}

void Physics::Move(const float dirX, const float dirY, float dt)
{
    velocity.x += dirX * acceleration.x * dt;
    velocity.y += dirY * acceleration.y * dt;
    
    if(std::abs(velocity.x) > velocityMax.x)
    {
        velocity.x = velocityMax.x * ((velocity.x < 0.f) ? -1.f : 1.f);
    }
    if(std::abs(velocity.y) > velocityMax.y)
    {
        velocity.y = velocityMax.y * ((velocity.y < 0.f) ? -1.f : 1.f);
    }
}

void Physics::Jump(const float force)
{
    velocity.y = force;
}

void Physics::Gravity(float dt)
{
    velocity.y += 1.0f * gravity * dt;
    if(std::abs(velocity.y) > velocityMax.y)
    {
        velocity.y = velocityMax.y * ((velocity.y < 0.f) ? -1.f : 1.f);
    }
}

bool Physics::CheckCollision(Object& obj)
{
    std::vector<glm::vec2> point1 = { {aabb.min.x, aabb.min.y}, {aabb.min.x, aabb.max.y}, {aabb.max.x, aabb.max.y}, {aabb.max.x, aabb.min.y} };
    std::vector<glm::vec2> point2 = { {obj.GetComponent<Physics>()->GetAABB().min.x, obj.GetComponent<Physics>()->GetAABB().min.y}, {obj.GetComponent<Physics>()->GetAABB().min.x, obj.GetComponent<Physics>()->GetAABB().max.y}, {obj.GetComponent<Physics>()->GetAABB().max.x, obj.GetComponent<Physics>()->GetAABB().max.y}, {obj.GetComponent<Physics>()->GetAABB().max.x, obj.GetComponent<Physics>()->GetAABB().min.y} };

    std::vector<glm::vec2> rotatedPoints1;
    std::vector<glm::vec2> rotatedPoints2;

    // 첫 번째 다각형 회전
    for (const glm::vec2& point : point1)
    {
        rotatedPoints1.push_back(RotatePoint(aabb, point, DegreeToRadian(Component::GetOwner()->GetRotate())));
    }

    // 두 번째 다각형 회전
    for (const glm::vec2& point : point2)
    {
        rotatedPoints2.push_back(RotatePoint(obj.GetComponent<Physics>()->GetAABB(), point, DegreeToRadian(obj.GetRotate())));
    }

    for (size_t i = 0; i < rotatedPoints1.size(); ++i)
    {
        glm::vec2 edge = rotatedPoints1[(i + 1) % rotatedPoints1.size()] - rotatedPoints1[i];
        glm::vec2 axis = glm::vec2(-edge.y, edge.x); // 수직인 축
        if (IsSeparatingAxis(axis, rotatedPoints1, rotatedPoints2))
        {
            return false; // 충돌이 없음
        }
    }

    for (size_t i = 0; i < rotatedPoints2.size(); ++i)
    {
        glm::vec2 edge = rotatedPoints2[(i + 1) % rotatedPoints2.size()] - rotatedPoints2[i];
        glm::vec2 axis = glm::vec2(-edge.y, edge.x); // 수직인 축
        if (IsSeparatingAxis(axis, rotatedPoints1, rotatedPoints2))
        {
            return false; // 충돌이 없음
        }
    }

    return true; // 모든 축에서 겹침이 없음
}

glm::vec2 Physics::PointPlusVector(glm::vec2 point, glm::vec2 vector)
{
    glm::vec2 result;
    result.x = point.x + vector.x;
    result.y = point.y + vector.y;
    return result;
}

glm::vec2 Physics::VectorPlusVector(glm::vec2 v0, glm::vec2 v1)
{
    glm::vec2 result;
    result.x = v0.x + v1.x;
    result.y = v0.y + v1.y;
    return result;
}

glm::vec2 Physics::VectorNormalize(glm::vec2 v)
{
    glm::vec2 result;
    float l = VectorLength(v);

    result.x =v.x / l;
    result.y =v.y / l;

    return result;
}

float Physics::VectorLength(glm::vec2 v)
{
    float l = sqrtf(v.x * v.x + v.y * v.y);
    return l;
}

glm::vec2 Physics::RotatePoint(AABB aabb_, const glm::vec2& point, float angle)
{
    float centerX = aabb_.max.x - aabb_.collisionBoxSize.x;
    float centerY = aabb_.max.y - aabb_.collisionBoxSize.y;
    float positionX = point.x - centerX;
    float positionY = point.y - centerY;

    float x = centerX + (positionX * cos(angle) - positionY * sin(angle));
    float y = centerY + (positionX * sin(angle) + positionY * cos(angle));
    return glm::vec2(x, y);
}

bool Physics::IsSeparatingAxis(const glm::vec2& axis, const std::vector<glm::vec2>& points1, const std::vector<glm::vec2>& points2)
{
    float min1 = INFINITY, max1 = -INFINITY;
    float min2 = INFINITY, max2 = -INFINITY;

    for (const glm::vec2& point : points1)
    {
        float projection = (point.x * axis.x) + (point.y * axis.y);
        min1 = std::min(min1, projection);
        max1 = std::max(max1, projection);
    }

    for (const glm::vec2& point : points2)
    {
        float projection = (point.x * axis.x) + (point.y * axis.y);
        min2 = std::min(min2, projection);
        max2 = std::max(max2, projection);
    }

    return !(max1 >= min2 && max2 >= min1);
}

void Physics::SetMinMax()
{
    aabb.min.x = GetOwner()->GetPosition().x + aabb.collisionBoxPosition.x - aabb.collisionBoxSize.x;
    aabb.max.x = GetOwner()->GetPosition().x + aabb.collisionBoxPosition.x + aabb.collisionBoxSize.x;
    aabb.min.y = GetOwner()->GetPosition().y + aabb.collisionBoxPosition.y - aabb.collisionBoxSize.y;
    aabb.max.y = GetOwner()->GetPosition().y + aabb.collisionBoxPosition.y + aabb.collisionBoxSize.y;
}
