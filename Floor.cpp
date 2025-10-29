#include "Floor.h"
#include "PaperFlipbookComponent.h"
#include "Engine.h"

AFloor::AFloor()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetZOrder(0);
	Paper->SetTexture(GEngine->GetTexture("Floor"));
	AddComponent(Paper);
	SetActorPaperComponent(Paper);
}

AFloor::~AFloor()
{

}
