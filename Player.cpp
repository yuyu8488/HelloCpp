#include "Player.h"
#include "FEngine.h"

APlayer::APlayer()
{
	ZOrder = 5;
}

APlayer::~APlayer()
{
	AActor::~AActor();
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	//FVector2D Location = GetActorLocation();
	switch (FEngine::GetInstance()->GetKeyCode())
	{
	case 'w':
		Location.Y--;
		break;
	case 's':
		Location.Y++;
		break;
	case 'a':
		Location.X--;
		break;
	case 'd':
		Location.X++;
		break;
	default:
		break;
	}
}

