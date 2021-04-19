#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using graph = vector<vector<long long>>;

void dfs(int u, const graph& gr, vll& used, vll& path, int& x)
{
	if (used[u] == 1)
		return;
	used[u] = 1;
	path[u] = x;
	x++;
	for (int v : gr[u])
	{
		dfs(v, gr, used, path, x);
	}
}




int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	graph gr(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	vll used(n, -1); 
	int res = 0;
	vll path(n, -1);
	int x = 0;
	dfs(k-1, gr, used, path, x);

	for (int i : path)
	{
		cout << i << " ";
	}

}