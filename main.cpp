#include "FEngine.h"
#include <vector>
#include <iostream>
#include <Windows.h>

#include "DynamicArray.h"
#include "Math.h"

DWORD WINAPI SecondThread(PVOID pvParam)
{
	*(int*)pvParam = 5;
	

	return NULL;
}

DWORD WINAPI FirstThread(PVOID pvParam)
{
	int x =  (int)pvParam;
	DWORD dwThreadID;

	HANDLE hThread = CreateThread(NULL, 0, SecondThread, (PVOID)&x, 0, &dwThreadID);

	CloseHandle(hThread);

	return(0);
}

int main(int argc, char* argv[])
{
	int a = 3;
	FirstThread((PVOID)&a);


	return 0;
}