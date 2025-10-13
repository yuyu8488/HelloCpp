#include <iostream>

#include "Object.h"
#include "Box.h"

int main()
{
	Object* NewObjects[10];

	NewObjects[0] = new Box();

	NewObjects[0]->SetTransfrom(30, 100);
	
	NewObjects[0]->Interact();

	return 0;
}