#pragma once

#define SDL_ENABLE_OLD_NAMES
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>
#include <ostream>

#include "Engine.h"
#include <typeinfo>

#pragma comment(lib, "SDL3")
#pragma comment(lib, "SDL3_image")


class MyClass {
public:
	void PrintClassName() {
		std::cout << "Class Name: " << typeid(*this).name() << std::endl;
	}
};
int SDL_main(int argc, char* argv[])
{
	//GEngine->Initialize();
	//GEngine->Run();
	//GEngine->Terminate();

	MyClass obj;
	obj.PrintClassName();
	return 0;

	return 0;
}