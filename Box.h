#pragma once
#include "Object.h"
class Box : public Object
{
public:
	Box();
	~Box();

	virtual void Interact() override;
};

