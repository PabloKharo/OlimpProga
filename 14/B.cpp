#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;

struct Edge {
	ll to, w;
};

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<Edge>> edges(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back(Edge{ v,w });
		edges[v].push_back(Edge{ u,w });
	}
	s--;
	vll distances(n, 1000000000);
	vll relaxed(n, 0);
	distances[s] = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1;
		for (int j = 0; j < n; j++)
		{
			if (!relaxed[j] && (u == -1 || distances[j] < distances[u]))
				u = j;
		}
		relaxed[u] = 1;

		for (const Edge& e : edges[u])
		{
			if (distances[e.to] > distances[u] + e.w)
				distances[e.to] = distances[u] + e.w;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (distances[i] == 1000000000)
			cout << "-1" << " ";
		else
			cout << distances[i] << " ";
	}


}