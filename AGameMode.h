#pragma once
#include "Actor.h"
class AGameMode : public AActor
{
public:
	AGameMode();
	virtual ~AGameMode() = default;

	virtual void Tick(float& DeltaTime) override;
};

