/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Particle.hpp
//Description: Header file for particle class
/*-------------------------------------------------------*/
#pragma once
#include "Component/Physics.hpp"
#include "Texture/Animation.hpp"
#include "Color/Color4f.hpp"

#include <string>

enum ParticleType
{
    REC,
    SPRI,
    ANIMESPRI
};

enum class ParticleEffect
{
    NORMAL,
    FADEOUT
};

class Particle
{
public:
    Particle() = default;
    Particle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime_, ParticleType type, std::string spriteName_, Color4f color_, float depth_, ParticleEffect particE = ParticleEffect::NORMAL);

    void Draw(float dt);
    bool inUse() const { return lifeTime > 0; }

    void SetFadeOutAmount(float amount) { fadeOutAmount = amount; }
    Animation* GetAnimation() { return &particleAnimation; }
    float GetLifetime() { return lifeTime; }
    Physics* GetPhysics() { return &pPhysics; }
private:
    glm::vec2 position = { 0.f, 0.f };
    glm::vec2 speed = { 0.f, 0.f };
    glm::vec2 size = { 0.f, 0.f };
    float depth = 1.f;
    float angle = 0.f;

    float fadeOutAmount = 0.1f;

    Color4f color = { 1.f,1.f,1.f,1.f };

    float lifeTime = 0;
    ParticleType particleType = REC;
    std::string spriteName = "";

    Animation particleAnimation;
    ParticleEffect effect;
    Physics pPhysics;
};