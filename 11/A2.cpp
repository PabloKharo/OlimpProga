#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;

int n;
vector<vector<ll>> c;
vector<vector<ll>> memo;
vll path;

ll dp(int last, int mask)
{
	if (memo[last][mask] != -1)
		return memo[last][mask];
	ll result = 100000000000;
	int prev_mask = mask ^ (1 << last);
	for (int i = 0; i < n; i++)
	{
		if (prev_mask & 1 << i)
			result = min(result, dp(i, prev_mask) + c[i][last]);
	}
	memo[last][mask] = result;
	return result;
}


int main()
{
	cin >> n;
	memo.resize(n, vll(1 << n, -1));
	c.resize(n, vll(n));
	memo[0][1] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		memo[i][0] = 100000000000;
	}

	ll result = 100000000000;
	for (int i = 0; i < n; i++)
	{
		result = min(result, dp(i, (1 << n) - 1)+c[i][0]);
	}
	cout << result;
}