#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void add(ll id, ll sl, ll sr, ll ql, ll qr, ll x, vll& data)
{
	if (ql <= sl && sr <= qr)
	{
		// добавить к элементу
		data[id] += x;
		return;
	}
	ll m = (sl + sr) / 2;
	if (ql <= m)
	{
		// добавить в левое поддерево
		add(id * 2 + 1, sl, m, ql, qr, x, data);
	}
	if (m < qr)
	{
		// добавить в правое поддерево
		add(id * 2 + 2, m + 1, sr, ql, qr, x, data);
	}

}

ll get(ll id, ll sl, ll sr, ll p, vll& data)
{
	// если нужный индекс
	if (sl == sr)
		return data[id];
	ll m = (sl + sr) / 2;
	// искать в левом поддереве
	if (p <= m)
		return get(id * 2 + 1, sl, m, p, data) + data[id];
	// искать в правом поддереве
	return get(id * 2 + 2, m + 1, sr, p, data) + data[id];
}

void build(ll id, ll sl, ll sr, const vll& a, vll& data)
{
	// если нужный индекс
	if (sl == sr)
	{
		data[id] = a[sl];
		return;
	}
	ll m = (sl + sr) / 2;
	// построить левое поддерево
	build(id * 2 + 1, sl, m, a, data);
	// построить правое поддерево
	build(id * 2 + 2, m + 1, sr, a, data);
}



int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin >> n;
	vll a(n);
	// считать все числа массива
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vll data(n * 4);
	// построить дерево
	build(0, 0, n - 1, a, data);
	int k;
	cin >> k;
	int s, l, r, x;
	for (int i = 0; i < k; i++)
	{
		cin >> s >> l;
		// если нужно вывести
		if (s == 0)
		{
			cout << get(0, 0, n - 1, l - 1, data) << '\n';
		}
		// прибавить значение
		else
		{
			cin >> r >> x;
			add(0, 0, n - 1, l - 1, r - 1, x, data);
		}

	}

}