#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();
	~Slime();

	virtual void Move() override;
};

