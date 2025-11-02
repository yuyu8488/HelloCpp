#pragma once
#include <vector>

#include "Core/Actor.h"


class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void GetAllActors(std::vector<AActor*>& OutActors) const;
	void SortActorsByZOrder();
	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick(float& DeltaTime);
	virtual void Render();

protected:
	std::vector<AActor*> Actors;
};

