#pragma once
#include "SceneComponent.h"
class UCollisionComponent : public USceneComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	bool CheckCollision(const UCollisionComponent* OtherComp);

protected:
	bool bIsCollision = false;
	bool bIsBlock = false;
	bool bIsOverlap = true;
};

