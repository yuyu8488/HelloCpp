#include <iostream>

#include "Game.h"

int main()
{
	Game* NewGame = new Game();
	if (NewGame->Initialize())
	{
		NewGame->Run();
	}

	delete NewGame;
	NewGame = nullptr;
}
