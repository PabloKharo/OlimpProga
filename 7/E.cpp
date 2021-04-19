#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	int mod = pow(10, 9) + 7;
	long long stepen = 1;
	int a;
	cin >> a;
	sum += a;
	for (int i = 1; i < n; i++)
	{
		cin >> a;
		sum += a;
		stepen *= 2;
		stepen %= mod;
	}

	long long ans = sum * stepen;
	ans %= mod;
	cout << ans;
	
}

