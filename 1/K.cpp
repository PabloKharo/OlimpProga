#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n, m, x, y, a, b;
	cin >> n >> m;
	cin >> x >> y;
	
	a = (n - 1) / x + 1;
	b = (m - 1) / y + 1;

	cout << a * b;
}

