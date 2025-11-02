#include "Player.h"
#include "../Engine.h"
#include "../World.h"
#include "../Components/PaperFlipbookComponent.h"
#include "../Components/CollisionComponent.h"

APlayer::APlayer() 
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetZOrder(10); 
	Paper->SetTexture(GEngine->GetTexture("Player"));
	AddComponent(Paper);
	SetActorPaperComponent(Paper);

	UCollisionComponent* Coll = GetActorCollisionComponent();
	Coll = new UCollisionComponent(true, true, true);
	CollComp = Coll;
	AddComponent(CollComp);
	SetActorCollisionComponent(CollComp);
}

APlayer::~APlayer()
{
	if (CollComp)
	{
		delete CollComp;
		CollComp = nullptr;
	}
}

void APlayer::Tick(float& DeltaTime)
{
	Move(DeltaTime);
}

void APlayer::Move(float& DeltaTime)
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

