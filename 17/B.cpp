#include <bits/stdc++.h>
//алгоритм краскала
using namespace std;
using ll = long long;
using vll = vector<long long>;

struct Res
{
	ll sum, max, min;
};


struct DSU {
	vll leaders;
	vll sizes;
	vector<Res> vRes;
	DSU(ll size)
	{
		leaders.resize(size);
		iota(leaders.begin(), leaders.end(), 0);
		sizes.resize(size, 1);
		vRes.resize(size);
		for (int i = 0; i < size; i++)
		{
			vRes[i].sum = i+1;
			vRes[i].min = i + 1;
			vRes[i].max = i + 1;
		}
	}

	ll find(ll u)
	{
		if (leaders[u] == u)
			return u;
		leaders[u] = find(leaders[u]);
		return leaders[u];
	}

	Res join(ll u, ll v)
	{
		u = find(u);
		v = find(v);

		if (u == v)
			return vRes[u];

		if (sizes[u] < sizes[v])
		{
			leaders[u] = v;
			sizes[v] += sizes[u];
			vRes[v].max = max(vRes[v].max, vRes[u].max);
			vRes[v].min = min(vRes[v].min, vRes[u].min);
			vRes[v].sum += vRes[u].sum;
			return vRes[v];
		}
		else
		{
			leaders[v] = u;
			sizes[u] += sizes[v];
			sizes[v] += sizes[u];
			vRes[u].max = max(vRes[v].max, vRes[u].max);
			vRes[u].min = min(vRes[v].min, vRes[u].min);
			vRes[u].sum += vRes[v].sum;
			return vRes[u];
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
		u--;
		v--;
		Res res = dsu.join(u, v);
		cout << res.sum << " " << res.min << " " << res.max <<'\n';
	}
}