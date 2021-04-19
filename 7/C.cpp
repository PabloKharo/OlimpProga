#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<long long> m(n+1);
	vector<long long> mass(n);
	int a, b;
	long long sum = 0;
	cin >> a;
	for (int i = 0; i < n-1; i++)
	{
		mass[i] = a;
		sum += a;
		cin >> b;
		m[i + 1] = max(a, b);
		sum += max(a, b);
		a = b;
	}
	mass[n-1] = a;
	sum += a;

	for (int i = 3; i <= n; i++) 
	{
		for (int k = 1; k <= i - 2; k++)
		{
			m[k] = max(m[k], mass[i-1]);
			sum += m[k];
		}
	}

	cout << sum;

}

