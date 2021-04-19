#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

long long BinPow(long long znam, int n, int mod)
{
	long long res = 1;
	while (n != 0)
	{
		if (n % 2 != 0)
			res = (res * znam) % mod;
		znam = (znam * znam) % mod;
		n /= 2;
	}
	return res;
}


int main()
{
	int n, m;
	int mod = pow(10, 9) + 7;
	cin >> n >> m;
	long long res = 1;
	if (n > m)
		swap(n, m);

	/*
	    (m+1)*(m+2)*...*(m+n)
	R = ----------------------
	     1 * 2 * 3 *... * n
	*/


	for (int i = 1; i <= n; i++)
	{
		// (n+i)
		res = (res *(m + i))%mod;
		// (n+i)/i
		res *= BinPow(i, mod - 2, mod);
		res %= mod;
	}

	cout << res;
}

