#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	virtual ~Player() {}

	void Move() override;
	void Attack();
	void Collect();
};

