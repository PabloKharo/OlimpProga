#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void sieva(long long numb, vector<int>& v, long long& res, 
											int m, int n)
{
	v[0] = 1;
	v[1] = 1;
	long long count = 0;
	for (long long i = 2; i <= numb; i++)
	{
		if (v[i] != 0)
			continue;
		count++;
		if (count >= n)
			res += i;
		if (count == m)
			break;
		for (long long k = i*i; k <= numb; k += i)
		{
			v[k] = 1;
		}
	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	long long res = 0;
	long long numb = 15485863;
	vector<int> v(numb + 1);
	sieva(numb, v, res, m, n);
	cout << res;
}

