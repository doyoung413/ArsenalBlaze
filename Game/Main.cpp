/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include "Application.hpp"

#include "Level/TestLevel.hpp"

#undef main
int main()
{
	Application application;

	application.Init("Arsenal Blaze", 640, 480, false, FrameRate::FPS_60);
	Instance::GetSpriteManager()->SetBackGroundColor({ 0.f,0.f,0.f,1.f });
	Instance::GetLevelManager()->AddLevel(new TestLevel());

	application.Update();

	application.End();

	return 0;
}
