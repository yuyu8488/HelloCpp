#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	void Move() override;
	void Attack();
	void Collect();
};

