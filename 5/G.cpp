#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
//бинарное возведение в степень
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
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int mod = pow(10, 9) + 7;
	int b, q, n;
	long long res = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> b >> q >> n;
		if (q != 1) 
		{
			// b*(q^n - 1)
			res = (b * (BinPow(q, n, mod) - 1)) % mod;
			// s = b*(q^n - 1) * a^-1
			res = res * BinPow(1 - q, mod - 2, mod);
			res %= mod;
			cout << res << '\n';
		}
		else
		{
			cout << (b * n) % mod << '\n';
		}
	}
}

