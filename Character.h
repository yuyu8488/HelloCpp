#pragma once
class Character
{
public:
	Character();
	~Character();

	int HP;
	int Gold;

	virtual void Move();
};

