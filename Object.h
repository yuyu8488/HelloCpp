#pragma once
#include <iostream>
class Object
{
public:
	Object();
	~Object();

	virtual void Interact() = 0;

	void SetTransfrom(int X, int Y)
	{
		std::cout << "이동한다 " << std::endl;

		PositionX = X;
		PositionY = Y;
	}

	int PositionX;
	int PositionY;
};

