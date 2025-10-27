#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Config.h"
#include "Engine.h"

AActor::AActor()
{
	
}

AActor::~AActor()
{
}

void AActor::Tick()
{
	
}

void AActor::Render()
{
	SDL_FRect DstRect = {Location.X * GRID_SIZE, Location.Y * GRID_SIZE, GRID_SIZE, GRID_SIZE};
	SDL_RenderTexture(GEngine->GetRenderer(), Texture, NULL, &DstRect);
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

