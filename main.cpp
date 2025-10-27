#define SDL_ENABLE_OLD_NAMES

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdio>
#include <string>
#include "FEngine.h"

#pragma comment(lib, "SDL3")

int SDL_main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	return 0;
}