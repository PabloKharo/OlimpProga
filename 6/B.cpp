#include <iostream>
#include <algorithm>
 
#include <vector>
 
#include <cmath>
using namespace std;
 
long long kuza(long long l, long long r)
{
	vector<long long> v(r + 1);
	long long mod = pow(10, 9) + 7;
	long long sum = 0;
	v[1] = 1;
	
	for (long long i = 1; i < r; i++)
	{	
		v[i] %= mod;
		if (i >= l)
		{
			sum += v[i];
			sum %= mod;
		}
		for (long long j = 2; j <= r / i; j++)
		{
			v[i * j] += v[i];
		}
 
	}
 
	sum += v[r];
	return sum % mod;
 
}
 
 
 
 
int main()
{
	long long l, r;
	cin >> l >> r;
	long long ans = kuza(l, r);
	cout << ans;
 
}
 