#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back


ll mex(vll& next)
{
	sort(next);
	if (next.empty() || next[0] != 0)
		return 0;
	for (int i = 1; i < next.size(); i++)
	{
		if (next[i] > next[i - 1] + 1)
			return next[i - 1] + 1;
	}
	return next.back() + 1;
}




int main()
{
	int n; 
	cin >> n;
	vll v(n);
	vector<ll> res(n);
	for (int i = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			res = res[i ^ v[i];
		}
	}
	


}
