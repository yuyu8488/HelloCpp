#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "PaperFlipbookComponent.h"

APlayer::APlayer() 
{
	PaperComp = new UPaperFlipbookComponent();
	PaperComp->SetZOrder(10);
	PaperComp->SetTexture(GEngine->GetTexture("Player"));
	AddComponent(PaperComp);

	bIsBlock = true;
	bIsCollision = true;
	bCanEverTick = true;
}

APlayer::~APlayer()
{
	AActor::~AActor();
}

void APlayer::Tick(float DeltaTime)
{
	Move(DeltaTime);
}

void APlayer::Move(float DeltaTime)
{
	FVector2D SaveLocation;
	SaveLocation = Location;
	switch (GEngine->GetKeyCode())
	{
	case SDLK_W:
	case SDLK_UP:
		Location.Y--;
		break;
	case SDLK_S:
	case SDLK_DOWN:
		Location.Y++;
		break;
	case SDLK_A:
	case SDLK_LEFT:
		Location.X--;
		break;
	case SDLK_D:
	case SDLK_RIGHT:
		Location.X++;
		break;
	case SDLK_ESCAPE:
		exit(-1);
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

