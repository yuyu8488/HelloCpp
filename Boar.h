#pragma once
#include "Monster.h"

class Boar : public Monster
{
public:
	Boar();
	~Boar();

	virtual void Move() override;

	void Rush();
};

