#pragma once

#include "Actor.h"

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster() override;

	virtual void Tick(float DeltaTime) override;

private:
	void Move(float DeltaTime);

	float ExecuteTime = 0.5f;
	float TotalTime = 0.f;
};

