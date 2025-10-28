#pragma once
#include <SDL3/SDL_render.h>

#include "Vector.h"
#include <vector>
#include <map>
#include <string.h>


class AActor
{
public:
	AActor();
	virtual ~AActor();
 
	virtual void Tick(float DeltaTime);

	__forceinline FVector2D GetActorLocation() const { return Location; }
	
	void SetActorLocation(const int& X, const int& Y);
	void SetActorLocation(const FVector2D& NewPos);

	void AddComponent(class UComponent* InComponent);

	std::vector<UComponent*> GetAllComponents() { return Components; }

	bool bCanEverTick	= true;
	virtual void ActorBeginOverlap();
	virtual void Hit();
	bool CheckCollision(const AActor* Other);
	bool bIsCollision = false;
	bool bIsBlock = false;
	bool bIsOverlap = true;
protected:
	FVector2D Location;

	std::vector<class UComponent*> Components;
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
