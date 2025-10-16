#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	virtual ~Player() override;

	virtual void Tick() override;

	void Move(const int& Input);
};

