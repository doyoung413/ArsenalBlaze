/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: LevelManager.hpp
//Description: Header file for level management
/*-------------------------------------------------------*/
#pragma once
#include "Level.hpp"
#include "LevelType.hpp"

#include <vector>

enum class State
{
	INIT,
	START,
	UPDATE,
	CHANGE,
	RESTART,
	PAUSE,
	END,
	SHUTDOWN,
};

class LevellManager
{
public:
	LevellManager() = default;
	~LevellManager();

	void Init();
	void Init(LevelType currentLevel_);

	void Update(float dt);
    void End();
	
	void AddLevel(Level* level);
	void ChangeLevel(LevelType changeLV);
	void RestartLevel();
	void SetGameState(State state_) { state = state_; }

	LevelType GetCurrentLevel() { return currentLevel; }
	State GetGameState() { return state; }
private:
	LevelType currentLevel = static_cast<LevelType>(0);
	LevelType changeLevel = static_cast<LevelType>(0);
	std::vector<Level*> levelList;
	State state = State::START;
};