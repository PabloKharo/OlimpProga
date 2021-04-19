#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
 
long long kuz(int n, int k)
{
	vector<long long> v(n + 1);
	long long mod = 1000000007;
	v[0] = 1;
 
	for (int i = 1; i <= n; i++)
	{
		
		for (int j = 1; j <= min(k, i); j++)
		{
			v[i] += v[i -j];
		}
		v[i] %= mod;
 
 
	}
	return v[n];
 
}
 
int main()
{
	int n, k;
	cin >> n >> k;
	cout << kuz(n, k);
 
 
}