#include "Game.h"
#include <iostream>



// 0 = °ø¹é
// 1 = º®(#)
// 2 = Player(P)
// 3 = Goal(G)

HANDLE ScreenBufferHandles[2];
int CurrentBufferIndex = 0;

int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

Game::Game()
{

}

Game::~Game()
{
	delete NewPlayer;

	Actors.clear();
}

bool Game::Initialize()
{
	NewPlayer = new Player();
	Actors.push_back(NewPlayer);

	return true;
}

bool Game::Update()
{
	for (Actor* actor : Actors)
	{
		actor->Tick();
		if (Player* MyPlayer = dynamic_cast<Player*>(actor))
		{
			MyPlayer->GetPosition();
		}
	}

	Render();

	return true;
}

void Game::Run()
{
	bool bRun = true;
	while (bRun)
	{
		bRun = Update();
	}
}

void Game::Render()
{
	system('cls');

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			int Type = Map[X][Y];
			switch (Type)
			{
			case 0:
				std::cout << " ";
				break;
			case 1:
				std::cout << "#";
				break;			
			case 2:				
				std::cout << "P";
				break;			
			case 3:				
				std::cout << "G";
 				break;
			default:
				break;
			}
		}
		std::cout << '\n';
	}
}


