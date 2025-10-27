#include "Player.h"
#include "FEngine.h"
#include "UWorld.h"

APlayer::APlayer()
{
	ZOrder = 5;
	bIsBlock = true;
}

APlayer::~APlayer()
{
	AActor::~AActor();
}

void APlayer::Tick()
{
	AActor::Tick();

	Move();
}

void APlayer::Move()
{
	FVector2D SaveLocation;
	SaveLocation = Location;
	switch (FEngine::GetInstance()->GetKeyCode())
	{
	case 'w':
		Location.Y--;
		break;
	case 's':
		Location.Y++;
		break;
	case 'a':
		Location.X--;
		break;
	case 'd':
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
		if (CheckCollision(OtherActor) && OtherActor != this)
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

