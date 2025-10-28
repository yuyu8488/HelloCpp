#include "Wall.h"
#include "PaperFlipbookComponent.h"
#include "Engine.h"

AWall::AWall()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetZOrder(3);
	Paper->SetTexture(GEngine->GetTexture("Wall"));
	AddComponent(Paper);

	bIsBlock = true;
	bIsOverlap = false;
	bCanEverTick = false;
}

AWall::~AWall()
{

}
