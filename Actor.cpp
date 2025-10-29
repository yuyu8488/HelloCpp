#include "Actor.h"
#include <iostream>
#include <Windows.h>

#include "CollisionComponent.h"
#include "Engine.h"
#include "Component.h"

AActor::AActor()
{
	
}

AActor::~AActor()
{
	for (auto Comp : Components)
	{
		if (Comp)
		{
			delete Comp;
			Comp = nullptr;
		}
	}

	if (CollisionComponent)
	{
		delete CollisionComponent;
		CollisionComponent = nullptr;
	}

	if (PaperFlipbookComponent)
	{
		delete CollisionComponent;
		CollisionComponent = nullptr;
	}
}

void AActor::Tick(float& DeltaTime)
{

}

void AActor::SetActorLocation(const int& X, const int& Y)
{
	Location.X = X;
	Location.Y = Y;
}

void AActor::SetActorLocation(const FVector2D& NewPos)
{
	Location = NewPos;
}

void AActor::AddComponent(UComponent* InComponent)
{
	InComponent->SetOwner(this);
	Components.push_back(InComponent);
}


