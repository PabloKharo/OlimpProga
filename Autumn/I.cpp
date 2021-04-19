#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// бинарное возведение числа по модулю
long long BinPow(long long znam, ll n, ll mod)
{
	long long res = 1;
	while (n != 0)
	{
		if (n % 2 != 0)
			res = (res * znam) % mod;
		znam = (znam * znam) % mod;
		n /= 2;
	}
	return res;
}

// хранит произведение чисел и 
// индекс последнего нулевого элемента
struct numb {
	ll num, zer = -1;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<numb> v(n+1);
	ll x;
	int l, r;
	int zer = -1;
	v[0].num = 1;
	ll ans = 0;
	ll mod = pow(10, 9) + 7;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		// если 0, то сохранить индекс нулевого элемента
		if (x == 0)
		{
			zer = i;
		}
		// если предыдущий элемент был нулевым,
		// то записать 
		if (v[i - 1].num == 0)
		{
			v[i] = { x, zer };
		}
		// посчитать произведение предыдущего произведения
		// и текущего числа
		else
			v[i] = { (v[i - 1].num * x) % mod, zer };
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		// если между концами был нулевой элемент
		if (v[r].zer >= l)
			ans = 0;
		else
		{
			// если перед левым концом были элементы,
			// то необходимо разделить на то произведение
			if (v[l - 1].num == 0)
				ans = v[r].num;
			else
				ans = (v[r].num * BinPow(v[l - 1].num, mod - 2, mod)) % mod;
		}

		cout << ans << '\n';
	}

}