#pragma once
#include "Component.h"

// 컴포넌트 구조 트리로 되어있음(언리얼)

class USceneComponent : public UComponent
{
public:
	USceneComponent();
	virtual ~USceneComponent();

	virtual void Tick() override;
	virtual void Render();
};

