#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long Nok(long long a, long long b)
{
	long long l = a;
	long long r = b;

	while (a != 0)
	{
		b %= a;
		swap(a, b);
	}
	

	return (r/b) * l;
}


int main()
{
	int n;
	cin >> n;

	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = n-1; i > 0; i--)
	{
		v[i-1] = Nok(v[i], v[i-1]);
		
		v.pop_back();
	}
	cout << v[0];
}

