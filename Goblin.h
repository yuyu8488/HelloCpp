#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	virtual void Move() override;
};

