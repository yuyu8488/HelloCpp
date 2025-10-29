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

	UCollisionComponent* Coll = new UCollisionComponent();


}

AWall::~AWall()
{

}
