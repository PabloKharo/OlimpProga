#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v(n);
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n > 1)
	{
		sort(v.begin(), v.end());
		int k = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			res += (n-1-k) * v[i];
			k += 2;
		}
		
	}

	cout << res;

}

