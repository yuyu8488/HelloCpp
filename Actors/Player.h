#pragma once
#include "../Core/Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer() override;

	virtual void Tick(float& DeltaTime) override;

private:
	void Move(float& DeltaTime);

	UCollisionComponent* CollComp;
};

