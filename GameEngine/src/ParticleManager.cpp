/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: ParticleManager.cpp
//Description: Source file for particle management
/*-------------------------------------------------------*/
#include "ParticleManager.hpp"


ParticleManager::~ParticleManager()
{
	Clear();
}

void ParticleManager::AddRandomParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, int particleAmount, Color4f color_, ParticleType type, std::string spriteName_, float depth)
{
	for (int i = 0; i < particleAmount; i++)
	{
		glm::vec2 newVel = { speed_.x + rand() % 5 - rand() % 5  , speed_.y + rand() % 5 - rand() % 5 };
		float tempVal = static_cast<float>(rand() % 5 - rand() % 5);
		glm::vec2 newSize = { size_.x + tempVal, size_.y + tempVal };
		float newAngle = { angle_ + rand() % 1 - rand() % 360 };
		particles.push_back(Particle(position_, newSize, newVel, newAngle, lifeTime, type, spriteName_, color_, depth));
	}
}

void ParticleManager::AddSingleParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, Color4f color_, ParticleType type, std::string spriteName_, float depth)
{
	//float newAngle = { angle_ + rand() % 1 - rand() % 360 };
	particles.push_back(Particle(position_, size_, speed_, angle_, lifeTime, type, spriteName_, color_, depth));
}

void ParticleManager::AddSingleFadeOutParticle(glm::vec2 position_, glm::vec2 size_, glm::vec2 speed_, float angle_, float lifeTime, Color4f color_, ParticleType type, std::string spriteName_, float depth, float decreaseAmount)
{
	particles.push_back(Particle(position_, size_, speed_, angle_, lifeTime, type, spriteName_, color_, depth, ParticleEffect::FADEOUT));
	GetLastParticle()->SetFadeOutAmount(decreaseAmount);
}

void ParticleManager::Draw(float dt)
{
	for (int i = 0; i < particles.size(); i++)
	{
		if (particles.at(i).inUse() == true)
		{
			particles.at(i).Draw(dt);
		}
		else
		{
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleManager::Clear()
{
	particles.clear();
}
