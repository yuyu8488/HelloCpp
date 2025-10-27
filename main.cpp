#define SDL_ENABLE_OLD_NAMES

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdio>
#include <string>
#include "FEngine.h"

#include "Vector.h"

#pragma comment(lib, "SDL3")

int SDL_main(int argc, char* argv[])
{
	SDL_Window* Window = SDL_CreateWindow("Game", 800, 640, SDL_WINDOW_OPENGL);

	
	

	
	SDL_DestroyWindow(Window);
	return 0;
}