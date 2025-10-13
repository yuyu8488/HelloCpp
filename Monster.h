#pragma once
#include "Character.h"

class Monster : public Character
{
public:
	Monster();
	~Monster();

	int HP;
	int Gold;

	void Drop();
	void Destroy();
};

