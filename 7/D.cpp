#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	long long res = 0;
	vector<long long> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		res += v[i] * (n - i) * (i + 1);
	}
	cout << res;

}

