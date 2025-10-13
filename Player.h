#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	int HP;
	int Gold;

	void Move() override;
	void Attack();
	void Collect();
};

