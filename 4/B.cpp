#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n, a0;
	cin >> n >> a0;
	int mod = pow(10, 9) + 7;
	long long f = 0;
	long long s = 0;
	long long k = 1;
	long long m;

	for (int i = 0; i < n; i++)
	{
		k *= 5;
		k %= mod;
		m = (a0 * k) % mod;
		if (m > s)
		{
			f = s;
			s = m;
		}

		else if (m > f)
			f = m;
	}
	
	cout << f << ' ' << s;
}

