#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
long long kuzop(int n, int k, vector<int>& opas)
{
	vector<long long> v(n + 1);
	v[0] = 1;
	long long mod = pow(10, 9) + 7;
	for (int i = 1; i <= n; i++)
	{
		if (opas[i])
			continue;
		for (int j = 1; j <= min(k, i); j++)
		{
			v[i] += v[i - j];
		}
		v[i] %= mod;
	}
	return v[n];
 
 
 
}
 
int main()
{
	int n, k, m, x;
	cin >> n >> k >> m;
	vector<int> opas(n + 1, 0);
 
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		opas[x] = 1;
	}
 
	cout << kuzop(n, k, opas);
 
}