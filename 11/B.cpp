#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> c(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}


	ll result = LLONG_MAX;
	vector<ll> path(n);
	iota(path.begin(), path.end(), 0);
	do 
	{
		ll cur = 0;
		for (int i = 1; i < n; i++) 
			cur += c[path[i - 1]][path[i]];
		result = min(result, cur);
	} while (next_permutation(path.begin() + 1, path.end()));
	cout << result;
}