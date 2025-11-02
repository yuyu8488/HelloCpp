#include "Input.h"
#include "../Engine.h"
#include <SDL3/SDL.h>

int UInput::KeyCode = 0;

UInput::UInput()
{
	
}

UInput::~UInput()
{

}

void UInput::Tick()
{
	if (GEngine->GetSDLEvent().key.down)
	{
		KeyCode = GEngine->GetSDLEvent().key.key;
	}
	else
	{
		KeyCode = 0;
	}	
}
