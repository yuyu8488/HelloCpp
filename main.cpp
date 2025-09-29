#include <iostream>

using namespace std;

// EntryPoint 
// Main ¿øÇü
int main(int argc, char* argv[])
{
	int Player[2] = { 0 };
	int* P = Player; 

	cout << Player[1] << endl;
	cout << *(Player+1) << endl;
	cout << *(P+1) << endl;

	return 0;
}