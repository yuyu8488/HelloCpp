#include "Wall.h"
#include "../Components/PaperFlipbookComponent.h"
#include "../Engine.h"
#include "../Components/CollisionComponent.h"

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
