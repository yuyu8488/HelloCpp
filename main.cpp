#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <random>

int Map[10][10] = {
	{ 1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1}
};

char PlayerShape = 'P';
int PlayerX = 1;
int PlayerY = 1;

char MonsterShape = 'M';
int MonsterX = 5;
int MonsterY = 5;

bool IsGameRunning = true;

void PlayerMove(const int& Input)
{
	if (Input == 'w')
	{
		if (Map[PlayerY - 1][PlayerX] != 1)
		{
			--PlayerY;
		}

	}
	else if (Input == 's')
	{
		if (Map[PlayerY + 1][PlayerX] != 1)
		{
			++PlayerY;
		}
	}
	else if (Input == 'a')
	{
		if (Map[PlayerY][PlayerX - 1] != 1)
		{
			--PlayerX;
		}
	}
	else if (Input == 'd')
	{
		if (Map[PlayerY][PlayerX + 1] != 1)
		{
			++PlayerX;
		}
	}
}
bool MonsterMove(int& PlayerX, int& PlayerY )
{
	// 몬스터 이동
	// 0,1,2,3 > 상하좌우 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 3);

	bool IsCatchPlayer = false;
	switch (dist(gen))
	{
	case 0:
		if (Map[MonsterY - 1][MonsterX] != 1)
		{
			--MonsterY;
			if (MonsterX == PlayerX && MonsterY == PlayerY)
			{
				IsCatchPlayer = true;
			}
		}
		break;
	case 1:
		if (Map[MonsterY + 1][MonsterX] != 1)
		{
			++MonsterY;
			if (MonsterX == PlayerX && MonsterY == PlayerY)
			{
				IsCatchPlayer = true;
			}
		}
		break;
	case 2:
		if (Map[MonsterY][MonsterX - 1] != 1)
		{
			--MonsterX;
			if (MonsterX == PlayerX && MonsterY == PlayerY)
			{
				IsCatchPlayer = true;
			}
		}
		break;
	case 3:
		if (Map[MonsterY][MonsterX + 1] != 1)
		{
			++MonsterX;
			if (MonsterX == PlayerX && MonsterY == PlayerY)
			{
				IsCatchPlayer = true;
			}
		}
		break;
	}

	return IsCatchPlayer;
}
void RenderMap()
{
	system("cls");
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (MonsterX == x && MonsterY == y)
			{
				std::cout << MonsterShape;
			}
			else if (PlayerX == x && PlayerY == y)
			{
				std::cout << PlayerShape;
			}
			else if (Map[x][y] == 1)
			{
				std::cout << "#";
			}
			else if (Map[x][y] == 0)
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
}

int main()
{
	while (IsGameRunning)
	{
		//Input
		const int Input = _getch();

		//Process
		PlayerMove(Input);	
		bool IsGameOver = MonsterMove(PlayerX, PlayerY);

		//Rendering
		RenderMap();

		if (IsGameOver)
		{
			std::cout << '\n' << "Game Over";
			system("pause");
		}
	}

	return 0;
}