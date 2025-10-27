#pragma once
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

	__forceinline FVector2D GetActorLocation() const 
	{ 
		return Location; 
	}
	__forceinline char GetShape() const
	{
		return Shape;
	}
	__forceinline int GetZOrder() const 
	{ 
		return ZOrder; 
	}

	void SetActorLocation(const int& X, const int& Y);
	void SetActorLocation(const FVector2D& NewPos);
	__forceinline void SetShape(const char& InShape) { Shape = InShape; }


	bool bIsCollision	= false;
	bool bIsBlock		= false;
	bool bIsOverlap		= true;

protected:
	char Shape;
	FVector2D Location;
	int ZOrder;

private:

};

