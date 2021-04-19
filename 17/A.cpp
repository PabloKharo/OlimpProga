#include <bits/stdc++.h>
//алгоритм краскала
using namespace std;
using ll = long long;
using vll = vector<long long>;

struct DSU {
	// вектор лидеров
	vll leaders;
	// вектор множеств
	vll sizes;
	// "конструктор" структуры
	DSU(ll size)
	{
		leaders.resize(size);
		iota(leaders.begin(), leaders.end(), 0);
		sizes.resize(size, 1);
	}
	// поиск лидера
	ll find(ll u)
	{
		// если элемент - лидер
		if (leaders[u] == u)
			return u;
		leaders[u] = find(leaders[u]);
		return leaders[u];
	}
	// обьединение множеств
	ll join(ll u, ll v)
	{
		u = find(u);
		v = find(v);

		if (u == v)
			return sizes[u];
		// присоединяем к меньшему множеству
		// для уменьшения количества операций.
		if (sizes[u] < sizes[v])
		{
			leaders[u] = v;
			sizes[v] += sizes[u];
			return sizes[v];
		}
		else
		{
			leaders[v] = u;
			sizes[u] += sizes[v];
			return sizes[u];
		}

	}

};

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v;
		// уменьшаем для нумерации с 0
		u--;
		v--;
		// обьединяем и выводим реузультат
		cout << dsu.join(u, v) << '\n';
	}
}