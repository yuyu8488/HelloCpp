#pragma once

#include "Character.h"

#include "Player.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"


class World
{
public:
	World();
	~World();

	Player Players[10];

	Goblin Goblins[5];
	Slime Slimes[5];
	Boar Boars[5];

	Character Characters[30];
};

