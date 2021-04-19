#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n;
	cin >> n;
	vector<vll> distances(n, vll(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> distances[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (distances[i][j] > distances[i][k] + distances[k][j])
					distances[i][j] = distances[i][k] + distances[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << distances[i][j] << " ";
		}
		cout << '\n';
	}

}