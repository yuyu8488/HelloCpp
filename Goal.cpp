#include "Goal.h"
#include "PaperFlipbookComponent.h"
#include "Engine.h"

AGoal::AGoal()
{
	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();
	Paper->SetZOrder(5);
	Paper->SetTexture(GEngine->GetTexture("Goal"));
	AddComponent(Paper);
}

AGoal::~AGoal()
{

}
