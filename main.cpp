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

	TDynamicArray<int> MyVec;
	MyVec.PushBack(1);
	MyVec.PushBack(2);
	MyVec.PushBack(3);
	MyVec.PushBack(4);
	MyVec.PushBack(5);
	TDynamicArray<int>::iterator iter;
	for (iter = MyVec.begin(); iter < MyVec.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	for (auto vec : MyVec)
	{
		std::cout << vec << ", ";
	}



	return 0;
}