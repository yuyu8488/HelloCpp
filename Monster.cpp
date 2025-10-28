#include "Monster.h"
#include "stdlib.h"
#include <vector>
#include "World.h"
#include "Engine.h"
#include "Config.h"
#include "PaperFilpbookComponent.h"

AMonster::AMonster()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetZOrder(6);
	Paper->SetTexture(GEngine->GetTexture("Monster"));
	AddComponent(Paper);

	bIsBlock = true;
}

AMonster::~AMonster()
{

}

void AMonster::Tick(float DeltaTime)
{
	Move(DeltaTime);
}

void AMonster::Move(float DeltaTime)
{
	TotalTime += DeltaTime;
	if (TotalTime <= ExecuteTime) return;
	
	TotalTime = 0;

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
