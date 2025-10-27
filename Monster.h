#pragma once

#include "Actor.h"

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster() override;

	virtual void Tick() override;

private:
	void Move();
};

