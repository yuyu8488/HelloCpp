//세상, 캐릭터(슬라임, 멧돼지, 고블린())
//
//캐릭터 -> 이동 가능, HP,
//플레이어(공격, 사냥을통한 골드 획득())
//몬스터(HP가 0이하가 되면 골드를 남겨놓고 사라짐())

class World
{
public:
	Player* NewPlayer = nullptr;
	Monster* NewMonsters[3];

};

class Character
{
public:
	virtual void Move();
	virtual void Death();

protected:
	int HP;
	int PositionX;
	int PositionY;
};

class Player : public Character
{
public:
	virtual void Move() override;
	virtual void Death() override;

protected:
	void Attack();
	
	int Gold;
};

class Monster : public Character
{
public:
	virtual void Move() override;
	virtual void Death() override;
};

class Slime : public Monster
{
public:

};

class Goblin : public Monster
{
public:

};

class WildBoar : public Monster
{
public:

};

int main()
{
	World* MyWolrd = new World();
	MyWolrd->NewMonsters[0] = new Slime();
	MyWolrd->NewMonsters[1] = new Slime();
	MyWolrd->NewMonsters[2] = new Slime();
}




