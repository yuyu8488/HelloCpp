#pragma once

#include "Actor.h"

class UCollisionCoponent;

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster() override;

	virtual void Tick(float DeltaTime) override;

private:
	void Move(float DeltaTime);

	UCollisionComponent* CollComp;
	
	float ExecuteTime = 0.5f;
	float TotalTime = 0.f;
};

