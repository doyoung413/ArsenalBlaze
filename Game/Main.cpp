/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include <SDL.h>
#include "Instance.hpp"

#undef main
int main()
{
	Window window;
	SpriteManager spriteManager;
	CameraManager cameraManager;
	InputManager inputManager;

	window.Init("Arsenal Blaze", 640, 480, false);
	spriteManager.InitRenderer("Assets/shader.vert", "Assets/shader.frag");
	spriteManager.SetBackGroundColor({ 1.f, 1.f, 1.f, 1.f });
	cameraManager.Init({ 640,480 });

	Instance::GetInstance().SetCameraManager(&cameraManager);
	Instance::GetInstance().SetSpriteManager(&spriteManager);
	Instance::GetInstance().SetInputManager(&inputManager);
	Instance::GetInstance().SetWindow(&window);

	SDL_Event e;
	while (1)
	{
		SDL_PollEvent(&e);

		cameraManager.Update();

		spriteManager.DrawStart();
		spriteManager.DrawRectangle({ 0.f,0.f,0.f }, 0.f, { 32.f,32.f,0.f }, {0.f,1.f,0.f,1.f}, 1.f);
		spriteManager.DrawEnd();

		if (inputManager.GetPressKey() != KEYBOARDKEYS::UNKNOWN)
		{
			std::cout << inputManager.KeyBoardToString(inputManager.GetPressKey()) << std::endl;
		}

		window.Update(e);
		inputManager.InputPollEvent(e);
	}

	Instance::GetInstance().SetCameraManager(nullptr);
	Instance::GetInstance().SetSpriteManager(nullptr);
	Instance::GetInstance().SetInputManager(nullptr);
	Instance::GetInstance().SetWindow(nullptr);

	window.End();
	SDL_Quit();
	return 0;
}
