#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

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
	string s;
	cin >> s;
	long long res = 1;
	int mod = pow(10, 9) + 7;
	vector<long long> srt(26, 1);
	long long cnt = 1;
	bool ok = true;
	sort(s.begin(), s.end());
	vector<long long> sr(26, 1);
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1])
			srt[s[i] - 'a'] += 1;
	}
	

	for (int i = s.length(); i > 0; i--)
	{
		res *= i;
		res %= mod;
	}
	int m = 0;

	for (int i = 0; i < 26; i++)
	{
		if (srt[i] != 1)
		{
			for (int j = 2; j <= srt[i]; j++)
			{
				sr[i] = (sr[i] * j) % mod;
			}
			sr[i] = BinPow(sr[i], mod - 2, mod);
			res = (res * sr[i]) % mod;
		}
	}

	cout << res;



}

