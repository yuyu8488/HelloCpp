#pragma once

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

	virtual void Init();
	virtual void Run();
	virtual void Term();

	_forceinline UWorld* GetWorld() const 
	{
		return World; 
	}

	_forceinline int GetKeyCode() const
	{
		return KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();

	UWorld* World;
	
	int KeyCode;
	bool bIsRunning = true;

protected:
	static FEngine* Instance;

};

#define GEngine FEngine::GetInstance()



