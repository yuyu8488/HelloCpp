#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int N; 
	unsigned long long X = 0;
	unsigned long long Result = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		
		unsigned long long NPOT = 2;
		for (int j=1; j < 64; j++)
		{
			if (NPOT >= X)
			{
				if (i == 0)
				{
					Result = NPOT;
				}
				else
				{
					Result^ NPOT;
					break;
				}
			}

			NPOT = NPOT << 2;
		}
	}


	return 0;
}