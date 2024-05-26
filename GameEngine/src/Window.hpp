/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Window.hpp
//Description: Header file for SDL window class
/*-------------------------------------------------------*/
#pragma once
#include "SDL.h"
#include "SDL_syswm.h"

#include "glm.hpp"
#include <memory>

class Window
{
public:
	Window() = default;
	~Window() = default;
	void Init(const char* title, int width, int height, bool fullscreen);

	void Update(SDL_Event event);
	void End();

	SDL_Window* GetWindow() { return window; };

	void ChangeWindowSize(int width, int height);
	glm::vec2 GetWindowSize() { return wSize; }

	bool IsFullscreen();
	void ToggleFullScreen();

	void SetScreenRatio(glm::vec2 amount) { screenRatio = amount; }
	glm::vec2 GetScreenRatio() { return screenRatio; }
private:
	void ResizeEventHandler(SDL_Window* window, int width, int height);
	void AspectRatio(int width, int height, glm::vec2 ratio);

	SDL_Window* window = nullptr;
	SDL_GLContext context;

	glm::vec2 screenRatio{ 4, 3 };
	glm::vec2 wSize = { 0,0 };
};