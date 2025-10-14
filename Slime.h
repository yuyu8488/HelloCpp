#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();

	virtual void Move() override;


	void Slide();
};

