/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Particle.cpp
//Description: Source file for particle class
/*-------------------------------------------------------*/
#include "Particle.hpp"
#include "Instance.hpp"

Particle::Particle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime_, ParticleType type, std::string spriteName_, Color4f color_, float depth_, ParticleEffect particE)
{
    position       = position_;
    size           = size_;
    speed          = speed_;
    angle          = angle_;
    this->lifeTime = lifeTime_;
    
    particleType = type;
    spriteName = spriteName_;
    color = color_;
    depth = depth_;
    effect = particE;

    if (particleType == ANIMESPRI)
    {
        particleAnimation = Instance::GetSpriteManager()->GetSprite(spriteName)->animation;
    }
}

void Particle::Draw(float dt)
{
    position.x += speed.x * dt;
    position.y += speed.y * dt;
    pPhysics.Gravity(dt);
    pPhysics.Update(dt, position);
    switch (effect)
    {
    case ParticleEffect::NORMAL:
        lifeTime -= dt;
        break;
    case ParticleEffect::FADEOUT:
        color.alpha -= fadeOutAmount * dt;
        lifeTime -= fadeOutAmount * dt;
        break;
    default:
        break;
    }

    if (size.x < 0)
    {
        size.x = 0;
    }
    if (size.y < 0)
    {
        size.y = 0;
    }

    switch (particleType)
    {   
    case REC:
        Instance::GetSpriteManager()->DrawRectangle({ position, 0.f }, angle, { size, 0.f }, color, depth);
        break;
    case SPRI:
        Instance::GetSpriteManager()->DrawSprite(spriteName, {position, 0.f}, angle, {size, 0.f}, color, depth);
        break;
    case ANIMESPRI:
        Instance::GetSpriteManager()->DrawSpriteWithAnimation(spriteName, particleAnimation, dt, {position, 0.f}, angle, {size, 0.f}, color, depth);
        break;
    }


}
