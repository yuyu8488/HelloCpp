#include "Floor.h"
#include "PaperFlipbookComponent.h"
#include "Engine.h"

AFloor::AFloor()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetZOrder(0);
	Paper->SetTexture(GEngine->GetTexture("Floor"));
	AddComponent(Paper);

	bIsBlock = false;
	bIsOverlap = false;
	bCanEverTick = false;
}

AFloor::~AFloor()
{

}
