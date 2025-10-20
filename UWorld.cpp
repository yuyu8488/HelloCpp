#include "UWorld.h"
#include "Actor.h"
#include <algorithm>

UWorld::UWorld()
{

}

UWorld::~UWorld()
{

}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors)
{
	OutActors = Actors;
}

void UWorld::SortActorsByZOrder()
{
	std::sort(Actors.begin(), Actors.end(), [](AActor* a, AActor* b) { return a->GetZOrder() < b->GetZOrder(); });
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
		Actor->Tick();
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}


