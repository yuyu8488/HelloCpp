#include "Goal.h"
#include "../Components/PaperFlipbookComponent.h"
#include "../Engine.h"

AGoal::AGoal()
{
	UPaperFlipbookComponent* Paper = new UPaperFlipbookComponent();
	Paper->SetZOrder(5);
	Paper->SetTexture(GEngine->GetTexture("Goal"));
	AddComponent(Paper);
	SetActorPaperComponent(Paper);
}

AGoal::~AGoal()
{

}
