#pragma once
class Character
{
public:
	Character();
	virtual ~Character();

	virtual void Move();

	int GetHP() const {	return HP; }
	int GetGold() const { return Gold; }
	void SetGold(const int& InValue) { Gold = InValue; }

protected:
	int HP;
	int Gold;

};

