#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
	string N;
	long long count = 0;
	cin >> N;
	for (long long i = 0; i < N.length(); i++)
	{
		if (N[i] - '0' == 0)
		{
			count++;
		}
		else if (N[i] - '4' == 0)
		{
			count++;
		}
		else if (N[i] - '6' == 0)
		{
			count++;
		}
		else if (N[i] - '8' == 0)
		{
			count += 2;
		}
		else if (N[i] - '9' == 0)
		{
			count++;
		}
	}
	cout << count;
}