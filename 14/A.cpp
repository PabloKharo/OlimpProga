#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;

struct Edge {
	ll u, v, w;
};

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;
	vector<Edge> edges(m);
	for (int i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[i].u = u; edges[i].v = v; edges[i].w = w;
	}
	s--;

	vll distances(n, 1000000000);
	distances[s] = 0;
	vll parents(n, -1);

	for (int i = 1; i < n; i++)
	{
		bool changed = false;
		for (const Edge& e : edges)
		{
			if (distances[e.v] > distances[e.u] + e.w)
			{
				distances[e.v] = distances[e.u] + e.w;
				parents[e.v] = e.u;
				changed = true;
			}
			if (distances[e.u] > distances[e.v] + e.w)
			{
				distances[e.u] = distances[e.v] + e.w;
				parents[e.u] = e.v;
				changed = true;
			}
		}

		if (!changed)
			break;

	}
	for (int i = 0; i < n; i++)
	{
		if (distances[i] == 1000000000)
			cout << "-1" << " ";
		else
			cout << distances[i] << " ";
	}

}