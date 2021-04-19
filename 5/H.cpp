#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
 
 
long long find(long long a, long long n)
{
	long long res = 1;
	long long mod = 1000000007;
	while (n != 0)
	{
		if (n % 2 != 0)
			res = res * a % mod;
		a = a * a % mod;
		n /= 2;
	}
	return res;
 
 
}
 
int main()
{
	int T;
	cin >> T;
	long long a, n;
	vector<long long> v(T);
	for (int i = 0; i < T; i++)
	{
		cin >> a >> n;
		v[i] = find(a, n);
 
	}
 
	for (long long c : v)
	{
		cout << c << '\n';
	}
 
 
}