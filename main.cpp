#pragma once

#define SDL_ENABLE_OLD_NAMES
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>
#include <ostream>

#include "Engine.h"

#pragma comment(lib, "SDL3")
#pragma comment(lib, "SDL3_image")

int SDL_main(int argc, char* argv[])
{
	GEngine->Initialize();
	GEngine->Run();
	GEngine->Terminate();

	return 0;
}