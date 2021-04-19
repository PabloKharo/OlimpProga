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
	long long mod = pow(10,9) +7;
	v[0] = 1;
	long long sum = 1;
	for (int i = 1; i <= n; i++)
	{
		v[i] = sum%mod;
		sum += v[i];
		if (i >= k)
			sum -= v[i - k];
	}

	return v[n];

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << kuz(n, k);


}

