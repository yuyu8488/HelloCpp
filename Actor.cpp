#include "Actor.h"
#include <iostream>
#include <Windows.h>
AActor::AActor()
{

}

AActor::~AActor()
{
}

void AActor::Tick()
{

}

void AActor::Render()
{
	COORD Posistion;
	Posistion.X = Location.X;
	Posistion.Y = Location.Y;

	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Posistion);
	std::cout << Shape;
}

void AActor::SetActorLocation(const int& X, const int& Y)
{
	Location.X = X;
	Location.Y = Y;
}

void AActor::SetActorLocation(const FVector2D& NewPos)
{
	Location = NewPos;
}
