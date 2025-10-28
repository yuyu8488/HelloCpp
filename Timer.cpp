#include "Timer.h"
#include "SDL3\SDL_timer.h"
#include <iostream>

UTimer::UTimer()
{
	CurrentTime = 0;
	LastTime = 0;
	DeltaSeconds = 0;
}

UTimer::~UTimer()
{

}

void UTimer::Tick()
{
	CurrentTime = SDL_GetTicks();
	DeltaSeconds = (float)(CurrentTime - LastTime) / 1000.f;
	LastTime = CurrentTime;
}
