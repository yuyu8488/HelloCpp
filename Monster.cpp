#include "Monster.h"
#include "stdlib.h"
#include <vector>
#include "World.h"
#include "Engine.h"
#include "PaperFlipbookComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetZOrder(6);
	Paper->SetTexture(GEngine->GetTexture("Monster"));
	AddComponent(Paper);
	SetActorPaperComponent(Paper);

	UCollisionComponent* Coll = GetActorCollisionComponent();
	Coll = new UCollisionComponent(true, true, true);
	CollComp = Coll;
	AddComponent(CollComp);
	SetActorCollisionComponent(CollComp);
}

AMonster::~AMonster()
{
	if (CollComp)
	{
		delete CollComp;
		CollComp = nullptr;
	}
}

void AMonster::Tick(float& DeltaTime)
{
	Move(DeltaTime);
}

void AMonster::Move(float& DeltaTime)
{
	TotalTime += DeltaTime;
	if (TotalTime <= ExecuteTime) return;
	
	TotalTime = 0;
		
	int Direction = SDL_rand(4);
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
		if (OtherActor != this && CollComp->CheckCollision(OtherActor))
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
