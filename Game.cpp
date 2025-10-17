#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

// 0 = ' '
// 1 = '#'
// 2 = Player
// 3 = Goal

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
	{1,0,0,0,0,0,0,0,3,1},
	{1,1,1,1,1,1,1,1,1,1},
};

Game::Game() : NewPlayer(nullptr)
{
}

Game::~Game()
{
	for (auto& actor : Actors)
	{
		if (actor)
		{
			delete actor;
			actor = nullptr;
		}
	}
	Actors.clear();

	if (NewPlayer)
	{
		NewPlayer = nullptr;
	}
}

bool Game::Initialize()
{
	Actors.clear();

	NewPlayer = new Player();
	if (!NewPlayer) return false;

	Actors.push_back(NewPlayer);

	return true;
}

void Game::Run()
{
	bool bRun = true;
	while (bRun)
	{
		bRun = Update();
	}

	system("cls");
	std::cout << "Goal Goal Goal Goal Goal" << "\n";
	std::cout << "Goal Goal Goal Goal Goal" << "\n";
	std::cout << "Goal                Goal" << "\n";
	std::cout << "Goal				      " << "\n";
	std::cout << "Goal				      " << "\n";
	std::cout << "Goal      Goal Goal Goal" << "\n";
	std::cout << "Goal      Goal Goal Goal" << "\n";
	std::cout << "Goal           Goal Goal" << "\n";
	std::cout << "Goal Goal Goal Goal Goal" << "\n";
	std::cout << "Goal Goal Goal Goal Goal" << "\n";
}

bool Game::Update()
{
	for (Actor* actor : Actors)
	{
		actor->Tick();
	}

	if (NewPlayer)
	{
		Vector2 BeforePos = NewPlayer->GetActorLocation();
		const int Input = _getch();
		NewPlayer->Move(Input);
		Vector2 AfterPos = NewPlayer->GetActorLocation();
		if (Map[AfterPos.X][AfterPos.Y] == 1)
		{
			NewPlayer->SetActorLocation(BeforePos);
		}
		else if (Map[AfterPos.X][AfterPos.Y] == 3)
		{
			bGoal = true;
		}
	}

	Render();

	return !bGoal;
}

void Game::Render()
{
	system("cls");

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			int Type = Map[X][Y];
			if (NewPlayer->GetActorLocation().X == X && NewPlayer->GetActorLocation().Y == Y)
			{
				std::cout << NewPlayer->GetShape();
				continue;
			}
			switch (Type)
			{
			case 0:
				std::cout << " ";
				break;
			case 1:
				std::cout << "#";
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


