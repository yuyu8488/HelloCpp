#include "PaperFlipbookComponent.h"
#include "Config.h"
#include "Engine.h"

UPaperFlipbookComponent::UPaperFlipbookComponent()
{

}

UPaperFlipbookComponent::~UPaperFlipbookComponent()
{

}

void UPaperFlipbookComponent::Tick()
{

}

void UPaperFlipbookComponent::Render()
{
	SDL_FRect DstRect = { 
		GetOwner()->GetActorLocation().X * GRID_SIZE, 
		GetOwner()->GetActorLocation().Y * GRID_SIZE, GRID_SIZE, GRID_SIZE };
	
	SDL_RenderTexture(GEngine->GetRenderer(), Texture, NULL, &DstRect);
}
