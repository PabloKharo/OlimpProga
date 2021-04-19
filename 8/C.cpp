#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;

ll dp(ll l, ll r, vector<vector<ll>>& memo, vector<ll> rows, vector<ll> colms)
{
	
	if (memo[l][r] != -1)
		return memo[l][r];
	if (l == r)
		return 0;
	ll res = dp(l + 1, r, memo, rows, colms) + rows[l] * colms[r] * colms[l];
	for (int k = l + 1; k < r; k++)
	{
		res = min(res, dp(l, k, memo, rows, colms) + dp(k + 1, r, memo, rows, colms) + rows[l] * colms[r] * colms[k]);
	}
	memo[l][r] = res;
	return res;
}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin >> n;
	ll l, r;
	vector<vector<ll>> memo(n+1, vector<ll>(n+1,-1));
	vector<ll> rows(n+1);
	vector<ll> colms(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> rows[i] >> colms[i];
	}
	ll res = dp(1, n, memo, rows, colms);
	cout << res;
}

