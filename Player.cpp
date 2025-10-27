#include "Player.h"
#include "Engine.h"
#include "World.h"

APlayer::APlayer()
{
	ZOrder = 5;
	bIsBlock = true;
	bIsCollision = true;
	bCanEverTick = true;
}

APlayer::~APlayer()
{
	AActor::~AActor();
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	FVector2D SaveLocation;
	SaveLocation = Location;
	switch (GEngine->GetKeyCode())
	{
	case SDLK_W:
		Location.Y--;
		break;
	case SDLK_S:
		Location.Y++;
		break;
	case SDLK_A:
		Location.X--;
		break;
	case SDLK_D:
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

