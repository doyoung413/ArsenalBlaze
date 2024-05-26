#include <SDL.h>

#undef main
int main()
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);

	SDL_Event* e = nullptr;
	while (1)
	{
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));
		SDL_UpdateWindowSurface(window);
		SDL_PollEvent(e);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
