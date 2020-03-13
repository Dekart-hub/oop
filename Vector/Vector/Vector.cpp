#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));

	for (auto f : numbers)
	{
		std::cout << f << " , ";
	}
}