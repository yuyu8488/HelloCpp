#pragma once

#include <map>
#include <string>
#include <vector>
#include <SDL3/SDL.h>
#include "Timer.h"

//#pragma comment(lib, "SDL3")
//#pragma comment(lib, "SDL3_image")

class UWorld;
class AActor;

class FEngine
{
protected:
	FEngine();

public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}
	virtual ~FEngine();

	virtual void Initialize();
	virtual void Run();
	virtual void Terminate();

	__forceinline UWorld* GetWorld() const 
	{
		return World; 
	}
	__forceinline Uint32 GetKeyCode() const
	{
		return KeyCode;
	}
	__forceinline SDL_Renderer* GetRenderer() const {return MainRenderer;}

	float GetWorldDeltaSeconds()
	{
		return Timer->GetDeltaSeconds();
	}
	SDL_Event GetSDLEvent() const { return MainEvent; }
	SDL_Texture* GetTexture(std::string Name) { return Textures[Name]; }


protected:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	
	Uint32 KeyCode; // InputDevice로 전환하기
	bool bIsRunning = true;

protected:
	static FEngine* Instance;
	
	SDL_Window* MainWindow = nullptr;
	SDL_Renderer* MainRenderer = nullptr;
	SDL_Event MainEvent;
	
	std::map<std::string, SDL_Texture*> Textures;
	
	class UTimer* Timer = nullptr;
	class UInput* InputDevice = nullptr;
private:
	bool LoadTextures();	
	void OpenLevel();
};

#define GEngine FEngine::GetInstance()



