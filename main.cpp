#include "FEngine.h"
#include <vector>
#include <iostream>
#include "DynamicArray.h"

int main(int argc, char* argv[])
{
	TDynamicArray<int> temp;
	temp.PushBack(1);
	temp.PushBack(2);
	
	for (int i = 0; i < temp.GetSize(); i++)
	{
		std::cout << temp[i] << std::endl;
	}
	return 0;
}
