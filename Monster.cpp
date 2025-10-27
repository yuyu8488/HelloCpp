#include "Monster.h"
#include "stdlib.h"
#include <vector>
#include "UWorld.h"
#include "FEngine.h"

AMonster::AMonster()
{
	ZOrder = 4;
	bIsBlock = true;
}

AMonster::~AMonster()
{

}

void AMonster::Tick()
{
	Move();
}

void AMonster::Move()
{
	int Direction = rand() % 4;
	FVector2D SaveLocation = GetActorLocation();

	switch (Direction)
	{
	case 0: //Up
		Location.Y--;
		break;
	case 1: //Down
		Location.Y++;
		break;
	case 2: //Left
		Location.X--;
		break;
	case 3: //Right
		Location.X++;
		break;
	default:
		break;
	}
	
	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);
	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (OtherActor != this && CheckCollision(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}

}
