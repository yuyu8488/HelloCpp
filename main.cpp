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

void PlayerMove(int Input)
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
void MonsterMove()
{
	// 몬스터 이동
// 0,1,2,3 > 상하좌우 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 3);

	switch (dist(gen))
	{
	case 0:
		if (Map[MonsterY - 1][MonsterX] != 1)
		{
			--MonsterY;
		}
		break;
	case 1:
		if (Map[MonsterY + 1][MonsterX] != 1)
		{
			++MonsterY;
		}
		break;
	case 2:
		if (Map[MonsterY][MonsterX - 1] != 1)
		{
			--MonsterX;
		}
		break;
	case 3:
		if (Map[MonsterY][MonsterX + 1] != 1)
		{
			++MonsterX;
		}
		break;
	}
}
void RenderMap()
{
	system("cls");
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (PlayerX == x && PlayerY == y)
			{
				std::cout << PlayerShape;
			}
			else if (MonsterX == x && MonsterY == y)
			{
				std::cout << MonsterShape;
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
	while (true)
	{
		//Input
		int Input = _getch();

		//Process
		PlayerMove(Input);
		MonsterMove();
		
		//Rendering
		RenderMap();
	}

	return 0;
}