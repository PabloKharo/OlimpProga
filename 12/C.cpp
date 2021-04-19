#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back



void add(ll id, ll sl, ll sr, ll qr, ll ql, ll x, vll& data)
{
	if (ql <= sl && sr <= qr)
	{
		data[id] += x;
		return;
	}
	ll m = (sl + sr) / 2;
	if (ql <= m)
	{
		data[id] += x;
		add(id * 2 + 1, sl, m, ql, qr, x, data);
	}
	if (m < qr)
	{
		data[id] += x;
		add(id * 2 + 2, m + 1, sr, ql, qr, x, data);
	}

}


void build(ll id, ll sl, ll sr, const vll& a, vll& data)
{
	if (sl == sr)
	{
		data[id] = a[sl];
		return;
	}
	ll m = (sl + sr) / 2;
	build(id * 2 + 1, sl, m, a, data);
	build(id * 2 + 2, m + 1, sr, a, data);
	data[id] = data[id * 2 + 1] + data[id * 2 + 2];
}


ll get(ll id, ll sl, ll sr, ll ql, ll qr, vll& data)
{
	if (ql <= sl && sr <= qr)
		return data[id];
	ll m = (sl + sr) / 2;

	if (qr <= m)
		return get(id * 2 + 1, sl, m, ql, qr, data);
	if (m < ql)
		return get(id * 2 + 2, m + 1, sr, ql, qr, data);
	return get(id * 2 + 1, sl, m, ql, qr, data) + get(id * 2 + 2, m + 1, sr, ql, qr, data);
}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int n;
	cin >> n;
	vll a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vll data(4 * n);
	build(0, 0, n - 1, a, data);

	int k;
	cin >> k;
	int q, l, r;
	for (int i = 0; i < k; i++)
	{
		cin >> q >> l >> r;
		if (q == 0)
		{
			cout << get(0, 0, n - 1, l - 1, r - 1, data) << '\n';
		}
		else
		{
			add(0, 0, n - 1, l - 1, l - 1, r, data);
		}

	}


}