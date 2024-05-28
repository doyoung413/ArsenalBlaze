/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Application.cpp
//Description: Source file for handling of the application
/*-------------------------------------------------------*/
#include "Application.hpp"

#include <iostream>

void Application::Input()
{
	if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::F))
	{
		window.ToggleFullScreen();
	}
	if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::ESCAPE))
	{
		levelManager.SetGameState(State::END);
	}
	if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::R))
	{
		levelManager.RestartLevel();
	}
	if (Instance::GetInputManager()->IsKeyPressOnce(KEYBOARDKEYS::P))
	{
		if (levelManager.GetGameState() == State::UPDATE)
		{
			levelManager.SetGameState(State::PAUSE);
		}
		else if (levelManager.GetGameState() == State::PAUSE)
		{
			levelManager.SetGameState(State::UPDATE);
		}
	}
}

Application::~Application()
{
	End();
}

void Application::Init(const char* title, int windowWidth, int windowHeight, bool fullScreen)
{
	window.Init(title, windowWidth, windowHeight, fullScreen);
	spriteManager.InitRenderer("Assets/shader.vert", "Assets/shader.frag");
	cameraManager.Init({ window.GetWindowSize().x, window.GetWindowSize().y });

	Instance::GetInstance().SetLevelManager(&levelManager);
	Instance::GetInstance().SetCameraManager(&cameraManager);
	Instance::GetInstance().SetSpriteManager(&spriteManager);
	Instance::GetInstance().SetWindow(&window);
	Instance::GetInstance().SetInputManager(&inputManager);
	Instance::GetInstance().SetObjectManager(&objectManager);
}

void Application::Update()
{
	SDL_Event event;
	while (levelManager.GetGameState() != State::SHUTDOWN)
	{
			SDL_PollEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
				levelManager.SetGameState(State::END);
				break;
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED || event.window.event == SDL_WINDOWEVENT_MOVED ||
					event.window.event == SDL_WINDOWEVENT_MINIMIZED)
				{
				}
				break;
			default:
				break;
			}

			inputManager.InputPollEvent(event);
			Input();
			levelManager.Update(1.f);
			window.Update(event);
	}
}

void Application::End()
{
	objectManager.DestroyAllObjects();
	spriteManager.GetShader().Delete();

	Instance::GetInstance().SetLevelManager(nullptr);
	Instance::GetInstance().SetCameraManager(nullptr);
	Instance::GetInstance().SetSpriteManager(nullptr);
	Instance::GetInstance().SetWindow(nullptr);
	Instance::GetInstance().SetInputManager(nullptr);
	Instance::GetInstance().SetObjectManager(nullptr);
}