#include <bits/stdc++.h>
//алгоритм краскала
using namespace std;
using ll = long long;
using vll = vector<long long>;

struct Edge
{
	ll from, to, weight;
};

using graph = vector<Edge>;

struct DSU {
	vll leaders;
	vll sizes;
	DSU(ll size)
	{
		leaders.resize(size);
		iota(leaders.begin(), leaders.end(), 0);
		sizes.resize(size, 1);
	}

	ll find(ll u)
	{
		if (leaders[u] == u)
			return u;
		leaders[u] = find(leaders[u]);
		return leaders[u];
	}

	bool join(ll u, ll v)
	{
		u = find(u);
		v = find(v);

		if (u == v)
			return false;

		if (sizes[u] < sizes[v])
		{
			leaders[u] = v;
			sizes[v] += sizes[u];
		}
		else
		{
			leaders[v] = u;
			sizes[u] += sizes[v];
		}

		return true;
	}


};

bool operator<(Edge l, Edge r)
{
	return l.weight < r.weight;
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph gr;
	for (int i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		u -= 1;
		v -= 1;
		gr.push_back({ u, v, w });
	}

	sort(gr.begin(), gr.end());

	DSU dsu(n);
	ll total = 0;
	for (Edge& e : gr)
	{
		if (dsu.join(e.from, e.to))
		{
			total += e.weight;
		}
	}
	cout << total;
}