#pragma once
#include "../Core/Component.h"


class USceneComponent : public UComponent
{
public:
	USceneComponent();
	virtual ~USceneComponent();

	virtual void Tick() override;
	virtual void Render();
};

