#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back

long long Nod(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return Nod(b, a % b);
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
	data[id] = Nod(data[id * 2 + 1], data[id * 2 + 2]);
}

long long get(long long id, long long sl, long long sr, long long ql, long long qr,vll& data)
{
	if (ql <= sl && sr <= qr)
		return data[id];
	long long m = (sl + sr) / 2;

	if (qr <= m)
		return get(id * 2 + 1, sl, m, ql, qr, data);
	if (m < ql)
		return get(id * 2 + 2, m + 1, sr, ql, qr, data);
	return Nod(get(id * 2 + 1, sl, m, ql, qr, data),get(id * 2 + 2, m + 1, sr, ql, qr, data));
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	long long n;
	cin >> n;
	vll data(n * 4);
	vll a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	build(0, 0, n - 1, a, data);
	int q;
	cin >> q;
	int l, r;
	for (int i= 0; i < q; i++)
	{
		cin >> l >> r;
		cout << get(0, 0, n-1, l-1, r-1, data) << '\n';
	}

	


}