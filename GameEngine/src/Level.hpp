/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Level.hpp
//Description: Header file for basic level class
/*-------------------------------------------------------*/
#pragma once

class Level
{
public:
	virtual ~Level(){};

	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Restart() = 0;
	virtual void End() = 0;
};