#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer() override;

	virtual void Tick() override;

	void Move();
	
private:

};

