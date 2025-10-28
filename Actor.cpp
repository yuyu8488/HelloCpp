#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Config.h"
#include "Engine.h"
#include "Component.h"

AActor::AActor()
{
	
}

AActor::~AActor()
{
}

void AActor::Tick(float DeltaTime)
{
	
}

void AActor::ActorBeginOverlap()
{
	
}

void AActor::Hit()
{

}

bool AActor::CheckCollision(const AActor* Other)
{
	if (bIsOverlap && Other->bIsOverlap)
	{
		return false;
	}
	if (bIsBlock && Other->bIsBlock && 
		Location == Other->Location)
	{
		return true;
	}
	return false;
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

