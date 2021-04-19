#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
struct ev
{
	long long pos, val;
};
 
bool operator<(ev& l, ev& r)
{
	if (l.pos != r.pos)
		return l.pos < r.pos;
	return l.val > r.val;
}
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<ev> even;
	vector<long long> mass(n);
	long long sum = 0, left, right, v;
	int k = 0, razn = 0;
	for (int i = 0; i < q; i++)
	{
		cin >> left >> right >> v;
		even.push_back(ev{ left, v });
		even.push_back(ev{ right + 1, -v });
	}
	sort(even.begin(), even.end());
	for (int i = 0; i < n; i++)
	{
		if(k > 0)
			razn = (even[k].pos - even[k - 1].pos);
		if (razn > 1)
		{
			for (int m = 0; m < razn-1; m++)
			{
				mass[i] = sum;
				i++;
			}
 
		}
		if (even[k].pos <= n)
		{
			if (even[k].pos == i+1)
			{
				sum += even[k].val;
				k++;
				while (even[k].pos == even[k - 1].pos && even[k].pos <= n)
				{
					sum += even[k].val;
					k++;
				}
			}
			mass[i] = sum;
		}
	}
 
	mass[n - 1] = sum;
 
	for (long long c : mass)
	{
		cout << c << ' ';
	}
}