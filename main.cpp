#include <iostream>

using namespace std;

/*
 테이블 -> C++
 Character
 ID Name Str Dex
 0   A    2
 1   B    3
 2   C    2

 // 데이터 모델링
 class Character
 {
	int ID;
	string Name;
	int Str;
	int Dex;
 }
 */

struct FRGB
{
	int R = 0;
	int G = 0;
	int B = 0;
};
struct FCoord
{
	int X = 0;
	int Y = 0;
};

class Image
{
public:
	FRGB RGB;
	FCoord Coord;
};

int main()
{
	Image* image = new Image;
	image->RGB.R = 1.f;
	image->RGB.G = 0.f;
	image->RGB.B = 0.f;


	return 0;
}

