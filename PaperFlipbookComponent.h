#pragma once
#include "SceneComponent.h"
class UPaperFlipbookComponent : public USceneComponent
{
public:
	UPaperFlipbookComponent();
	virtual ~UPaperFlipbookComponent();

	__forceinline int GetZOrder() const { return ZOrder; }
	__forceinline SDL_Texture* GetTexture() const { return Texture; }

	__forceinline void SetZOrder(const int& InZOrder) { ZOrder = InZOrder; }
	__forceinline void SetTexture(SDL_Texture* InTexture) { Texture = InTexture; }

	virtual void Tick() override;
	virtual void Render() override;

protected:
	SDL_Texture* Texture;
	int ZOrder;
};

