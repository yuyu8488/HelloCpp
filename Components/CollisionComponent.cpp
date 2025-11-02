#include "CollisionComponent.h"
#include "../World.h"

UCollisionComponent::UCollisionComponent()
{

}

UCollisionComponent::UCollisionComponent(bool InIsCollision, bool InIsBlock, bool InIsOverlap)
{
	bIsCollision = InIsCollision;
	bIsBlock = InIsBlock;
	bIsOverlap = InIsOverlap;
}

UCollisionComponent::~UCollisionComponent()
{

}

bool UCollisionComponent::CheckCollision(const AActor* OtherActor)
{
	UCollisionComponent* PrimitiveComp = GetOwner()->GetActorCollisionComponent();
	UCollisionComponent* OtherComp = OtherActor->GetActorCollisionComponent();

	if (!PrimitiveComp || !OtherComp)
	{
		return false;
	}

	if (bIsOverlap && OtherComp->bIsOverlap)
	{
		return false;
	}
	
	if (bIsBlock && OtherComp->bIsBlock &&
		GetOwner()->GetActorLocation() == OtherActor->GetActorLocation())
	{
		return true;
	}
	
	return false;
}
