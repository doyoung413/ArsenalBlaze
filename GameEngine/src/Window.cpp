/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Window.cpp
//Description: Source file for SDL window class
/*-------------------------------------------------------*/
#include "Window.hpp"
#include <GL/glew.h>

#include "SDL_opengl.h"
#include <iostream>

void Window::Init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	wSize.x = (float)width;
	wSize.y = (float)height;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0)
	{
		std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			(int)wSize.x, (int)wSize.y, flags | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	}
	context = SDL_GL_CreateContext(GetWindow());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glewInit();

	SDL_GL_SetSwapInterval(true);
	std::cout << "Create Window Successful" << '\n' << std::endl;

	AspectRatio(width, height, screenRatio);
	glViewport(0, 0, width, height);
}

void Window::Update()
{
	if ((event.type == SDL_WINDOWEVENT) && (event.window.event == SDL_WINDOWEVENT_RESIZED || event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED))
	{
		ResizeEventHandler(window, event.window.data1, event.window.data2);
		AspectRatio(event.window.data1, event.window.data2, screenRatio);
	}
	SDL_GL_SwapWindow(window);
}

void Window::End()
{
	SDL_DestroyWindow(window);
}

void Window::ChangeWindowSize(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

bool Window::IsFullscreen()
{
	int flags = SDL_GetWindowFlags(window);
	if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == 1)
	{
		return true;
	}
	return false;
}

void Window::ToggleFullScreen()
{
	if (IsFullscreen() == true)
	{
		SDL_SetWindowFullscreen(window, false);
	}
	else
	{
		SDL_SetWindowFullscreen(window, true);
	}

}

void Window::ResizeEventHandler(SDL_Window* /*window*/, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::AspectRatio(int width, int height, glm::vec2 ratio)
{
	viewPortSize = { width, height };
	if (width * ratio.y > height * ratio.x)
	{
		viewPortSize.x = height * ratio.x / ratio.y;
		viewPort.x = (width - viewPortSize.x) / 2;
	}
	else if (width * ratio.y < height * ratio.x)
	{
		viewPortSize.y = width * ratio.y / ratio.x;
		viewPort.y = (height - viewPortSize.y) / 2;
	}

	glViewport(static_cast<int>(viewPort.x), static_cast<int>(viewPort.y), static_cast<int>(viewPortSize.x), static_cast<int>(viewPortSize.y));
}
