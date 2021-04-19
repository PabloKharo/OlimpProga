#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long Divs(long long n)
{
	long long divs = 0;
	long long i = 1;
	while (i * i < n)
	{
		if (n % i == 0)
			divs += 2;
		i++;
	}

	if (i * i == n)
		divs += 1;
	return divs;

}

int main()
{
	long long n;
	cin >> n;

	cout << Divs(n);
	
}

