#pragma once

#include "Actor.h"
class AWall : public AActor
{
public:
	AWall();
	virtual ~AWall() override;

protected:
	class UPaperFlipbookComponent* PaperComp;
	class UCollisionComponent* CollisionComp;
};

