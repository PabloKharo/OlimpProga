#include <iostream>
#include <algorithm>
 
#include <vector>
 
#include <cmath>
using namespace std;
 
 
long long lok(int n, int m, vector<vector<long long>>& opas)
{
	vector<vector<long long>> mp(n + 1, vector<long long>(m + 1));
	long long mod = 1000000007;
	bool okx = true;
	bool oky = true;
	mp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (opas[i][j])
				continue;
	
 
			if (i > 0 )
				mp[i][j] += mp[i - 1][j];
			if (j > 0)
				mp[i][j] += mp[i][j - 1];
			mp[i][j] %= mod;
 
		}
 
 
	}
	return mp[n][m];
 
}
 
 
int main()
{
	int n, m, k, x ,y;
	cin >> n >> m >> k;
 
	vector<vector<long long>> opas(n+1, vector<long long>(m + 1));
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		opas[x][y] = 1;
	}
 
	cout << lok(n, m, opas);
 
 
}