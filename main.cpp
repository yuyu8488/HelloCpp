#include <iostream>

using namespace std;

// EntryPoint 
// Main ����
int main(int argc, char* argv[])
{
	int CurrentHP = 1000;
	int MaxHP = 100;
	float Percent = 0.f;

	// ����ȯ
	Percent = static_cast<float>(CurrentHP) / static_cast<float>(MaxHP);

	cout << Percent << endl;

	return 0;
}