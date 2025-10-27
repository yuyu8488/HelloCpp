#include "World.h"
#include "Actor.h"
#include <algorithm>

UWorld::UWorld()
{

}

UWorld::~UWorld()
{

}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}

void UWorld::SortActorsByZOrder()
{
    std::sort(Actors.begin(), Actors.end(), [](AActor* a, AActor* b) { return a->GetZOrder() < b->GetZOrder(); });

	//for (int j = 0; j < Actors.size(); ++j)
	//{
	//	for (int i = 0; i < Actors.size(); ++i)
	//	{
	//		if (Actors[j]->GetZOrder() < Actors[i]->GetZOrder())
	//		{
	//			AActor* Temp = Actors[j];
	//			Actors[j] = Actors[i];
	//			Actors[i] = Temp;
	//		}
	//	}
	//}
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		Actors.push_back(NewActor);
	}
	return NewActor;
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		if (Actor->bCanEverTick)
		{
			Actor->Tick();
		}
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}


