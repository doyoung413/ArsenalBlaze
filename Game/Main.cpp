/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include <SDL.h>
#include "Instance.hpp"

#include "Level/TestLevel.hpp"

#undef main
int main()
{
	Window window;
	SpriteManager spriteManager;
	CameraManager cameraManager;
	InputManager inputManager;
	ObjectManager objectManager;
	LevellManager levelManager;

	window.Init("Arsenal Blaze", 640, 480, false);
	spriteManager.InitRenderer("Assets/shader.vert", "Assets/shader.frag");
	spriteManager.SetBackGroundColor({ 1.f, 1.f, 1.f, 1.f });
	cameraManager.Init({ 640,480 });

	Instance::GetInstance().SetCameraManager(&cameraManager);
	Instance::GetInstance().SetSpriteManager(&spriteManager);
	Instance::GetInstance().SetInputManager(&inputManager);
	Instance::GetInstance().SetObjectManager(&objectManager);
	Instance::GetInstance().SetLevelManager(&levelManager);
	Instance::GetInstance().SetWindow(&window);

	levelManager.AddLevel(new TestLevel());
	SDL_Event e;
	while (1)
	{
		SDL_PollEvent(&e);
		levelManager.Update(1.f);
		window.Update(e);
		inputManager.InputPollEvent(e);
	}
	objectManager.DestroyAllObjects();
	levelManager.End();

	Instance::GetInstance().SetCameraManager(nullptr);
	Instance::GetInstance().SetSpriteManager(nullptr);
	Instance::GetInstance().SetInputManager(nullptr);
	Instance::GetInstance().SetObjectManager(nullptr);
	Instance::GetInstance().SetLevelManager(nullptr);
	Instance::GetInstance().SetWindow(nullptr);

	window.End();
	SDL_Quit();
	return 0;
}
