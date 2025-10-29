#pragma once
#include "Actor.h"


class UPaperFlipbookComponent;
class UCollisionComponent;

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer() override;

	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);

protected:
	UCollisionComponent* CollComp;
};

