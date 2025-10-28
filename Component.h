#pragma once
#include "Actor.h"

class AACtor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0;

	AActor* GetOwner() const { return Owner; }
	void SetOwner(AActor* Actor) { Owner = Actor; }
protected:
	AActor* Owner;
};

