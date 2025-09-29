#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE ScreenBufferHandles[2];
int CurrentBufferIndex = 0;

struct FCharacter
{
	int X;
	int Y;
	string Shape;
};

FCharacter Characters[2];

int KeyCode;

void Input()
{
	KeyCode = _getch();
}

void RenderCharacter(FCharacter* InData)
{
	COORD Position;
	Position.X = static_cast<SHORT>(InData->X);
	Position.Y = static_cast<SHORT>(InData->Y);

	SetConsoleCursorPosition(ScreenBufferHandles[CurrentBufferIndex], Position);
	WriteConsole(ScreenBufferHandles[CurrentBufferIndex], InData->Shape.c_str(), 1, nullptr, nullptr);
	SetConsoleActiveScreenBuffer(ScreenBufferHandles[CurrentBufferIndex]);
}

void Clear(HANDLE InHandle)
{
	COORD coordScreen = { 0, 0 };    
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	if (!GetConsoleScreenBufferInfo(InHandle, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(InHandle,
		(TCHAR)' ',
		dwConSize,
		coordScreen,
		&cCharsWritten));
	{
		return;
	}

	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(InHandle, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(InHandle,         // Handle to console screen buffer
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute
		coordScreen,      // Coordinates of first cell
		&cCharsWritten))  // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(InHandle, coordScreen);
}

void Present()
{
	CurrentBufferIndex++;
	CurrentBufferIndex = CurrentBufferIndex % 2;
}

void Render()
{
	Clear(ScreenBufferHandles[CurrentBufferIndex]);

	for (int i = 0; i < 2; ++i)
	{
		RenderCharacter(&Characters[i]);
	}

	Present();

}

void MovePlayer()
{
	if (KeyCode == 'w')
	{
		Characters[0].Y--;
	}
	else if (KeyCode == 's')
	{
		Characters[0].Y++;
	}
	else if (KeyCode == 'a')
	{
		Characters[0].X--;
	}
	else if (KeyCode == 'd')
	{
		Characters[0].X++;
	}
}

void MoveMonster()
{
	int Direction = rand() % 4;
	switch (Direction)
	{
	case 0://Up
		Characters[1].Y--;
		break;
	case 1://Down
		Characters[1].Y++;
		break;
	case 2://Left
		Characters[1].X--;
		break;
	case 3://Right
		Characters[1].X++;
		break;
	default:
		break;
	}
}

void Init()
{
	ScreenBufferHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	ScreenBufferHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Characters[0].X = 1;
	Characters[0].Y = 1;
	Characters[0].Shape = 'P';

	Characters[1].X = 10;
	Characters[1].Y = 10;
	Characters[1].Shape = 'M';
}

void Tick()
{
	MovePlayer();
	MoveMonster();
}

//entrypoint
int main()
{
	FCharacter* Data = new FCharacter();
	delete Data;

	Init();

	while (true)
	{
		Input();
		Tick();
		Render();
	}

	return 0;
}