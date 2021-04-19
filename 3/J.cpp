#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;



int main()
{
	int n, k;
	cin >> n >> k;
	long long res = 0;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		if (i % k != k-1)
			res += v[i];
	}

	cout << res;

}

