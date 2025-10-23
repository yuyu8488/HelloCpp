#include "FEngine.h"
#include <vector>
#include <iostream>
#include "DynamicArray.h"

int main(int argc, char* argv[])
{
	std::vector<int> vec = { 10, 20, 30, 40, 50 };
	std::vector<int>::iterator it;
	for (it = vec.begin(); it < vec.end(); it++)
	{
		//std::cout << *it << std::endl;
	}

	return 0;
}