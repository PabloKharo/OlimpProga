#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<ll>> v(n, vector<ll>(n));
	vector<vector<ll>> v2(n, vector<ll>(n));
	vector<vector<ll>> v3(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v2[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				v3[i][j] += v[i][k] * v2[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v3[i][j] << ' ';
		}
		cout << '\n';
	}
}