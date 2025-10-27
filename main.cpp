#include "FEngine.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include "DynamicArray.h"
#include "Math.h"
#include <DirectXMath.h>
#include "Vector.h"


int main(int argc, char* argv[])
{
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();	

	return 0;
}

//DirectX::XMFLOAT4X4();

//Math::Matrix4x4 Zero = Math::Matrix4x4();
//Math::Matrix4x4 OnetoFour = Math::Matrix4x4(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);

//Math::Matrix4x4 Sum = Zero + OnetoFour;

//std::vector<float> A;