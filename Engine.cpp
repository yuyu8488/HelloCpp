#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>

#include <SDl3/SDL_image.h>

#include "Config.h"
#include "World.h"
#include "AGameMode.h"

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() :
	World(nullptr), KeyCode()
{
	
}

FEngine::~FEngine()
{

}

void FEngine::Initialize()
{
	SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO );
	MainWindow = SDL_CreateWindow("Game", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	MainRenderer = SDL_CreateRenderer(MainWindow, nullptr);
	SDL_SetRenderDrawBlendMode(MainRenderer, SDL_BLENDMODE_BLEND);

	LoadTextures();
	
	World = new UWorld();
	std::ifstream MapFile("Level01.txt");
	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0 };
		int Y = 0;
		while (MapFile.getline(Buffer, 80))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetTexture(Textures["Wall"]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetTexture(Textures["Player"]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetTexture(Textures["Monster"]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetTexture(Textures["Goal"]);
					World->SpawnActor(NewActor);
				}

				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetTexture(Textures["Floor"]);
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}
	World->SortActorsByZOrder();
	World->SpawnActor(new AGameMode());
	MapFile.close();
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Terminate()
{
	for (const std::pair<const std::string, SDL_Texture*>& texture : Textures)
	{
		SDL_DestroyTexture(texture.second);
	}
	Textures.clear();
	
	SDL_DestroyRenderer(MainRenderer);
	SDL_DestroyWindow(MainWindow);
}

void FEngine::Input()
{
	KeyCode = NULL;
}

void FEngine::Tick()
{
	SDL_PollEvent(&MainEvent);
	switch (MainEvent.type)
	{
	case SDL_EVENT_QUIT:
		bIsRunning = false;
		break;
	case SDL_EVENT_KEY_DOWN:
		KeyCode = MainEvent.key.key;
		break;		
	default:
		break;
	}

	GetWorld()->Tick();
}

void FEngine::Render()
{
	SDL_SetRenderDrawColor(MainRenderer, 255, 255, 255, 255);
	SDL_RenderClear(MainRenderer);
//=======================================Begin Draw=======================================//
	
	/* Grid */
	SDL_SetRenderDrawColor(MainRenderer, 0, 0, 0, 30);
	for (float X = 0; X <= WINDOW_WIDTH; X += GRID_SIZE)
	{
		SDL_RenderLine(MainRenderer, X, 0, X, WINDOW_HEIGHT);
	}
	for (float Y = 0; Y <= WINDOW_HEIGHT; Y += GRID_SIZE)
	{
		SDL_RenderLine(MainRenderer, 0, Y, WINDOW_WIDTH, Y);
	}

	GetWorld()->Render();
	
	// SDL_FRect DstRect = {0.f, 0.f, TEST_SIZE, TEST_SIZE};
	// SDL_RenderTexture(MainRenderer, Textures["Wall"], NULL, &DstRect);
	
//=======================================End Draw=======================================//
	SDL_RenderPresent(MainRenderer);
}

bool FEngine::LoadTextures()
{
	SDL_Surface* Surface = IMG_Load("Resource/Floor.png");
	Textures["Floor"] = SDL_CreateTextureFromSurface(MainRenderer, Surface);
	Surface = IMG_Load("Resource/Goal.png");
	Textures["Goal"] = SDL_CreateTextureFromSurface(MainRenderer, Surface);
	Surface = IMG_Load("Resource/Wall.png");
	Textures["Wall"] = SDL_CreateTextureFromSurface(MainRenderer, Surface);
	Surface = IMG_Load("Resource/Player.png");
	Textures["Player"] = SDL_CreateTextureFromSurface(MainRenderer, Surface);
	Surface = IMG_Load("Resource/Monster.png");
	Textures["Monster"] = SDL_CreateTextureFromSurface(MainRenderer, Surface);
	SDL_DestroySurface(Surface);

	return true;
}
