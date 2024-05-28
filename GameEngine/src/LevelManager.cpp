/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: LevelManager.cpp
//Description: Source file for level management
/*-------------------------------------------------------*/
#include "LevelManager.hpp"
#include "Instance.hpp"

LevellManager::~LevellManager()
{
	End();
}

void LevellManager::Init()
{
	levelList.at(static_cast<int>(currentLevel))->Init();
}

void LevellManager::Init(LevelType currentLevel_)
{
	currentLevel = currentLevel_;
	Init();
	state = State::UPDATE;
}

void LevellManager::Update(float dt)
{
	switch (state)
	{
	case State::START:
		if (levelList.empty())
		{
			state = State::SHUTDOWN;
		}
		else
		{
			state = State::INIT;
		}
		break;
	case State::INIT:
		Init();
		state = State::UPDATE;
		break;
	case State::UPDATE:
		Instance::GetCameraManager()->Update();

		Instance::GetSpriteManager()->DrawStart();
		Instance::GetObjectManager()->Update(dt);
		Instance::GetObjectManager()->CollideObjects();
		levelList.at(static_cast<int>(currentLevel))->Update(dt);
		Instance::GetParticleManager()->Draw(dt);
		Instance::GetSpriteManager()->DrawEnd();
		break;
	case State::PAUSE:
		Instance::GetCameraManager()->Update();

		Instance::GetSpriteManager()->DrawStart();
		Instance::GetObjectManager()->Update(0.f);
		levelList.at(static_cast<int>(currentLevel))->Update(0.f);
		Instance::GetParticleManager()->Draw(0.f);
		Instance::GetSpriteManager()->DrawEnd();
		break;
	case State::CHANGE:
		levelList.at(static_cast<int>(currentLevel))->End();
		currentLevel = changeLevel;
		state = State::INIT;
		break;
	case State::RESTART:
		levelList.at(static_cast<int>(currentLevel))->End();
		state = State::INIT;
		break;
	case State::END:
		levelList.at(static_cast<int>(currentLevel))->End();
		state = State::SHUTDOWN;
		break;
	case State::SHUTDOWN:
		break;
	}
}

void LevellManager::End()
{
	for (auto& lev : levelList)
	{
		delete lev;
	}
	levelList.clear();
}

void LevellManager::AddLevel(Level* level)
{
	levelList.push_back(level);
}

void LevellManager::ChangeLevel(LevelType changeLV)
{
	changeLevel = changeLV;
	state = State::CHANGE;
}

void LevellManager::RestartLevel()
{
	state = State::RESTART;
}
