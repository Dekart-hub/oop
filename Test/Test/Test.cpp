#include <iostream>

using namespace std;
int main()
{
	int counter = 0;
	for (int i = 1; i < 51; i++)
	{
		if ((i - 14) ^ 2 / (i - 10) <= (i - 14) ^ 2 / (i - 25))
		{
			counter++;
		}
		cout << i << '|';
	}
	cout << "\n--->" << counter;
}