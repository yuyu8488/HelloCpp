#include "World.h"
#include "Actor.h"
#include <algorithm>
#include "SceneComponent.h"
#include "PaperFlipbookComponent.h"

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
    //std::sort(Actors.begin(), Actors.end(), [](AActor* a, AActor* b) { return a->GetZOrder() < b->GetZOrder(); });
	std::sort(Actors.begin(), Actors.end(), [](AActor* A, AActor* B) {

		UPaperFlipbookComponent* PaperComp1 = A->GetActorPaperComponent();
		UPaperFlipbookComponent* PaperComp2 = B->GetActorPaperComponent();

		if (!PaperComp1 || !PaperComp2)
		{
			return false;
		}
		return PaperComp1->GetZOrder() < PaperComp2->GetZOrder();
	});
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		Actors.push_back(NewActor);
	}
	return NewActor;
}

void UWorld::Tick(float DeltaTime)
{
	for (auto Actor : Actors)
	{
		if (Actor->bCanEverTick)
		{
			Actor->Tick(DeltaTime);
		}
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for (UComponent* Comp : Actor->GetAllComponents())
		{
			if (USceneComponent* SceneComp = dynamic_cast<USceneComponent*>(Comp))
			{
				SceneComp->Render();
			}
		}
	}
}


