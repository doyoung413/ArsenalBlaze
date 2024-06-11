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
}

Application::~Application()
{
	End();
}

void Application::Init(const char* title, int windowWidth, int windowHeight, bool fullScreen, FrameRate frameRate)
{
	window.Init(title, windowWidth, windowHeight, fullScreen);
	spriteManager.InitRenderer("Assets/shader.vert", "Assets/shader.frag");
	cameraManager.Init({ window.GetWindowSize().x, window.GetWindowSize().y });

	gameManager.Init();

	Instance::GetInstance().SetLevelManager(&levelManager);
	Instance::GetInstance().SetCameraManager(&cameraManager);
	Instance::GetInstance().SetSpriteManager(&spriteManager);
	Instance::GetInstance().SetInputManager(&inputManager);
	Instance::GetInstance().SetObjectManager(&objectManager);
	Instance::GetInstance().SetParticleManager(&particleManager);
	Instance::GetInstance().SetBackgroundManager(&backgroundManager);
	Instance::GetInstance().SetSoundManagerManager(&soundManager);
	Instance::GetInstance().SetWindow(&window);

	Instance::GetInstance().SetGameManager(&gameManager);

	timer.Init(frameRate);
}

void Application::Update()
{
	SDL_Event event;
	float deltaTime = 0.f;
	int frameCount = 0;
	std::chrono::system_clock::time_point lastTick;
	std::chrono::system_clock::time_point fpsCalcTime;

	while (levelManager.GetGameState() != State::SHUTDOWN)
	{
		timer.Update();
		deltaTime = timer.GetDeltaTime();
		if (deltaTime > 1.f / static_cast<float>(timer.GetFrameRate()))
		{
			SDL_PollEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
				levelManager.SetGameState(State::END);
				break;
			case SDL_WINDOWEVENT:
				if ((event.window.event != SDL_WINDOWEVENT_RESIZED) || (event.window.event != SDL_WINDOWEVENT_MOVED) ||
					(event.window.event == SDL_WINDOWEVENT_MINIMIZED))
				{
					deltaTime = 0.f;
				}
				break;
			default:
				break;
			}
			timer.ResetLastTimeStamp();
			frameCount++;
			if (frameCount >= static_cast<int>(timer.GetFrameRate()))
			{
				int averageFrameRate = static_cast<int>(frameCount / timer.GetFrameRateCalculateTime());
				std::cout << averageFrameRate << std::endl;
				timer.ResetFPSCalculateTime();
				frameCount = 0;
			}
			inputManager.InputPollEvent(event);

			Input();
			levelManager.Update(deltaTime * 60.f);
			window.Update(event);
		}
	}
}

void Application::End()
{
	objectManager.DestroyAllObjects();
	spriteManager.GetShader().Delete();
	particleManager.Clear();

	Instance::GetInstance().SetLevelManager(nullptr);
	Instance::GetInstance().SetCameraManager(nullptr);
	Instance::GetInstance().SetSpriteManager(nullptr);
	Instance::GetInstance().SetWindow(nullptr);
	Instance::GetInstance().SetInputManager(nullptr);
	Instance::GetInstance().SetParticleManager(nullptr);
	Instance::GetInstance().SetObjectManager(nullptr);
	Instance::GetInstance().SetGameManager(nullptr);
	Instance::GetInstance().SetBackgroundManager(nullptr);
	Instance::GetInstance().SetSoundManagerManager(nullptr);
}