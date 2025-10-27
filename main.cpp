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
	//GEngine->Init();
	//GEngine->Run();
	//GEngine->Term();


	FVector3 Vec1 = FVector3(3, 4, 2);
	FVector3 Vec2 = FVector3(4, 2, 1);
	
	float temp = Vec1.Dot(Vec2);
	

	return 0;
}