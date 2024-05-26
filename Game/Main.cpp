/*-------------------------------------------------------*/
//Author: Doyoung Lee (doyoung413@gmail.com)
//File: Main.cpp
//Description: Source file for main function
/*-------------------------------------------------------*/
#include <SDL.h>
#include "Window.hpp"

#undef main
int main()
{
	Window window;
	window.Init("Arsenal Blaze", 640, 480, false);

	SDL_Event e;
	while (1)
	{
		SDL_PollEvent(&e);
		window.Update(e);
	}

	window.End();
	SDL_Quit();
	return 0;
}
