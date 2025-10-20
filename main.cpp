#include "FEngine.h"

int main(int argc, char* argv[])
{
	if (FEngine* NewEngine = GEngine)
	{
		NewEngine->Init();
		NewEngine->Run();
		NewEngine->Term();

		delete NewEngine;
		NewEngine = nullptr;
	}

	return 0;
}
