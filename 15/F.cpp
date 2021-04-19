#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct zhuk
{
	int p;
	char d;
};

bool operator<(zhuk l, zhuk r)
{
	if (l.d != r.d)
		return l.d < r.d;
	if (l.d = 'R')
		return l.p > r.p;
	return l.p < r.p;
}

int main()
{
	int n, l;
	cin >> n >> l;
	vector<zhuk> zhuki(n);
	int ans = 0;
	bool ok = true;

	for (int i = 0; i < n; i++)
	{
		cin >> zhuki[i].p >> zhuki[i].d;
	}

	sort(zhuki.begin(), zhuki.end());

	if (zhuki.front().d == 'R')
		ans = l - zhuki.back().p;
	else if (zhuki.back().d == 'L')
		ans = zhuki.front().p;
	else
		ans = max(zhuki.front().p, l - zhuki.back().p);
	cout << ans;

}