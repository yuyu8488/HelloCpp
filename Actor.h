#pragma once
#include <SDL3/SDL_render.h>

#include "Vector.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();
 
	virtual void Tick();
	virtual void Render();
	
	virtual void ActorBeginOverlap();
	virtual void Hit();
	bool CheckCollision(const AActor* Other);

	__forceinline FVector2D GetActorLocation() const { return Location; }
	__forceinline char GetShape() const{return Shape;}
	__forceinline int GetZOrder() const { return ZOrder; }
	__forceinline SDL_Texture* GetTexture() const {return Texture;}

	void SetActorLocation(const int& X, const int& Y);
	void SetActorLocation(const FVector2D& NewPos);
	__forceinline void SetShape(const char& InShape) { Shape = InShape; }
	__forceinline void SetZOrder(const int& InZOrder) { ZOrder = InZOrder; }
	__forceinline void SetTexture(SDL_Texture* InTexture) {Texture = InTexture;} 

	
	bool bIsCollision	= false;
	bool bIsBlock		= false;
	bool bIsOverlap		= true;

	bool bCanEverTick	= true;
protected:
	char Shape;
	FVector2D Location;
	int ZOrder;

	SDL_Texture* Texture;
};



// 충돌처리를 비트연산으로 바꾸기
// Actor Collision Type > WorldStatic, WorldDynamic, Pawn,
// 
//				 Ignore, Overlap, Block
// WorldStatic	   0		0		1
// WorldDynamic    0		0		1
// Pawn			   0		1		0

// 0x 0000 / 0000 
// 앞의 4자리는 CollisionType / 뒤 4자리는 Ignor, Overlap, Block;

//uint8_t CollisionFlag = 0;
//uint8_t BlockFlag = 0x00000001;
//uint8_t OverlapFlag = 0x00000010;
