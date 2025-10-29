#include "Wall.h"
#include "PaperFlipbookComponent.h"
#include "Engine.h"
#include "CollisionComponent.h"

AWall::AWall()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetZOrder(3);
	Paper->SetTexture(GEngine->GetTexture("Wall"));
	AddComponent(Paper);
	SetActorPaperComponent(Paper);

	UCollisionComponent* Coll = GetActorCollisionComponent();
	Coll = new UCollisionComponent(true, true, false);
	AddComponent(Coll);
	SetActorCollisionComponent(Coll);
}

AWall::~AWall()
{
	
}
