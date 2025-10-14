#include <iostream>

#include "World.h"
#include <vector>

int main()
{
	std::vector<Monster*> Monsters;

	srand((unsigned int)(time(nullptr)));

	int MonsterTypeNum = 3;
	int MonsterCount = 10;

	for (int i = 0; i < MonsterCount; i++)
	{
		int MonsterID = rand() % MonsterTypeNum + 1;
		switch (MonsterID)
		{
		case 1:
			Monsters.push_back(new Slime());
			break;
		case 2:
			Monsters.push_back(new Goblin());
			break;
		case 3:
			Monsters.push_back(new Boar());
			break;
		}
	}

	for (Monster* Mon : Monsters)
	{
		Mon->Move();
	}

	for (const Monster*& Mon : Monsters)
	{
		delete Mon;
		Mon = nullptr;
	}
	Monsters.clear();

}
