#include "GameMode.h"
#include <vector>
#include "../Engine.h"
#include "../World.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"

AGameMode::AGameMode()
{

}

void AGameMode::Tick(float& DeltaTime)
{
	AActor* Player = nullptr;
	std::vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);
	
	if (Player == nullptr)
	{
		for (AActor* Actor : AllActors)
		{
			if (dynamic_cast<APlayer*>(Actor))
			{
				Player = dynamic_cast<APlayer*>(Actor);
				break;
			}
		}
	}

	if (Player)
	{
		for (AActor* Actor : AllActors)
		{
			if (dynamic_cast<AMonster*>(Actor))
			{
				if (Player->GetActorLocation() == Actor->GetActorLocation())
				{
					//exit(-1);
				}
			}
		}

		for (AActor* Actor : AllActors)
		{
			if (dynamic_cast<AGoal*>(Actor))
			{
				if (Player->GetActorLocation() == Actor->GetActorLocation())
				{
					exit(-1);
				}
			}
		}
	}

	SDL_Log("deltaSeconds : %f", GEngine->GetWorldDeltaSeconds());
}