#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	~Goblin();

	virtual void Move() override;
};

