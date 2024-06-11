/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include "Application.hpp"

#include "Level/TestLevel.hpp"
#include "Level/Shop.hpp"
#include "Level/Option.hpp"

#include "FileManager.hpp"

#undef main
int main()
{
	Application application;

	application.Init("A", 640, 480, false, FrameRate::FPS_60);
	Instance::GetWindow()->SetScreenRatio({ 4,3 });
	Instance::GetSoundManager()->Initialize(8);

	Instance::GetSpriteManager()->SetBackGroundColor({ 0.f,0.f,0.f,1.f });
	Instance::GetLevelManager()->AddLevel(new Option());
	Instance::GetLevelManager()->AddLevel(new Shop());
	Instance::GetLevelManager()->AddLevel(new TestLevel());

	FileManager::LoadSetting("../Setting.ini");
	application.Update();

	application.End();
	
	return 0;
}
