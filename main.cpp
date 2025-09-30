#include <iostream>
using namespace std;

class Engine
{
public:
	void Run()
	{
		while (true)
		{
			Input();
			Tick();
			Render();
		}
	}

	void Input()
	{

	}

	void Tick()
	{

	}

	void Render()
	{

	}

	World* 
};

class World
{
public:
	void GameOver()
	{

	}

	AWall* Wall = nullptr;
	AFloor* Floor = nullptr;

	APlayer* Player = nullptr;
	AMonster* Monster = nullptr;

	ADestination Destination;
};

class APlayer
{
public:
	void Move()
	{
		
	}

	int PositionX;
	int PositionY;
};

class AMonster
{
public:
	void Move()
	{

	}

	int PositionX;
	int PositionY;
};

class AWall
{
public:
	int SizeX = 0;
	int SizeY = 0;
};

class AFloor
{
public:
	int SizeX = 0;
	int SizeY = 0;
};

class ADestination
{
public:
	int PositionX;
	int PositionY;
};

int main()
{
	
	return 0;
}
