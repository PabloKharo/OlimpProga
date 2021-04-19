#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using graph = vector<vector<long long>>;


void bfs(int s, graph& gr, vll& lvls, vll path)
{
	lvls.assign(gr.size(), -1);
	lvls[s] = 0;
	queue<ll> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : gr[u])
		{
			if (lvls[v] != -1)
				continue;
			lvls[v] = lvls[u] + 1;
			q.push(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	graph gr(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	vll lvls;
	vll path(n, -1);
	bfs(k, gr, lvls, path);


	int x = 0;
	for (int i : lvls)
	{
		if( x != 0)
			cout << i << " ";
		x++;
	}
}