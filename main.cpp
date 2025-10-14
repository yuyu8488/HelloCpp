#include <iostream>

#include "World.h"
#include <vector>

int main()
{
	std::vector<Monster*> Monsters;

	int SlimeCount = rand() % 5;
	int GoblinCount = rand() % 5;

	for (int i = 0; i < SlimeCount; i++)
	{
		Monsters.push_back(new Slime());
	}

	for (int i = 0; i < GoblinCount; i++)
	{
		Monsters.push_back(new Goblin());
	}

	for (Monster* Mon : Monsters)
	{
		Mon->Move();
	}

	for (Monster*& Mon : Monsters)
	{
		delete Mon;
		Mon = nullptr;
	}
}
