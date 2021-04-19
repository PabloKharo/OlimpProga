#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> cp(n);
	vector<int> zero;
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];	
		if (v[i] == 0)
			zero.push_back(i);
		if (v[i] > n)
		{
			ok = false;
			break;
		}
	}
	cp = v;
	sort(cp.begin(), cp.end());
	reverse(zero.begin(), zero.end());
	for (int i = 1; i < n; i++)
	{
		if (!ok)
			break;
		if (cp[i] == cp[i - 1] && cp[i] != 0)
			ok = false;
		if (cp[i] != cp[i-1] + 1)
		{
			for (int k = cp[i-1] + 1; k < cp[i]; k++)
			{
				v[zero.back()] = k;
				zero.pop_back();
			}
		}
	}

	

	if (ok)
	{
		if (zero.size() != 0)
		{
			int si = zero.size();
			for (int i = 1; i <= si; i++)
			{
				v[zero.back()] = cp.back() + i;
				zero.pop_back();
			}
		}
		cout << n << '\n';
		for (int c : v)
		{
			cout << c << ' ';
		}
	}
	else
	{
		cout << "-1";
	}
}

