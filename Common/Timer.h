#pragma once

#include "SDL3/SDL_time.h"

class UTimer
{
public:
	UTimer();
	virtual ~UTimer();
	float& GetDeltaSeconds() { return DeltaSeconds; }
	
	void Tick();
protected:
	SDL_Time CurrentTime;
	SDL_Time LastTime;

	float DeltaSeconds;

};

