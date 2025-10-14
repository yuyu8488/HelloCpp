#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	void Move() override;

	void Run();
};

