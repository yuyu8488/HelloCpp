#pragma once

#include <vector>
#include "Actor.h"
#include "Player.h"

#include <iostream>


class Game
{
public:
	Game();
	virtual ~Game();

	bool Initialize();
	bool Update();

	void Render();
	void Run();

private:
	std::vector<Actor*> Actors;
	Player* NewPlayer;
	
};

