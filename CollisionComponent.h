#pragma once
#include "SceneComponent.h"
class UCollisionComponent : public USceneComponent
{
public:
	UCollisionComponent();
	UCollisionComponent(bool InIsCollision, bool InIsBlock, bool InIsOverlap);
	//UCollisionComponent& operator=(UCollisionComponent) {}

	virtual ~UCollisionComponent();


	bool CheckCollision(const AActor* OtherActor);

protected:
	bool bIsCollision = false;
	bool bIsBlock = false;
	bool bIsOverlap = true;
};

