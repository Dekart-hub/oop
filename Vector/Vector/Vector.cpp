#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	vector<float> ReplayBuffer;
	for (string f; getline(cin, f, ',');)
	{
		ReplayBuffer.push_back(stof(f));
	}

	for (auto f : ReplayBuffer)
	{
		std::cout << f << " , ";
	}
}