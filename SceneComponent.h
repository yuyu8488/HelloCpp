#pragma once
#include "Component.h"

// ������Ʈ ���� Ʈ���� �Ǿ�����(�𸮾�)

class USceneComponent : public UComponent
{
public:
	USceneComponent();
	virtual ~USceneComponent();

	virtual void Tick() override;
	virtual void Render();
};

