/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: ParticleManager.hpp
//Description: Header file for particle management
/*-------------------------------------------------------*/
#pragma once
#include "Particle.hpp"

#include <vector>

class ParticleManager
{
public:
	ParticleManager() {}
    ~ParticleManager();

    void AddRandomParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, int particleAmount, Color4f color_ = { 1.f,1.f,1.f,1.f }, ParticleType type = REC, std::string spriteName_ = "", float depth = 1.f);
	void AddSingleParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, Color4f color_ = { 1.f,1.f,1.f,1.f }, ParticleType type = REC, std::string spriteName_ = "", float depth = 1.f);
	void AddSingleFadeOutParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, Color4f color_ = { 1.f,1.f,1.f,1.f }, ParticleType type = REC, std::string spriteName_ = "", float depth = 1.f, float decreaseAmount = 0.1f);

	void Draw(float dt);
	void Clear();
	Particle* GetLastParticle() { return &particles.at(particles.size() - 1); }
private:
	std::vector<Particle> particles;
};