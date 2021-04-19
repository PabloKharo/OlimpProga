#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;

using graph = vector<vector<long long>>;

vll path;
int ok = 0;

bool dfs(int u, int p, graph& gr, vll& color)
{
	if (color[u] == 1)
	{
		path.push_back(u);
		return true;
	}
	color[u] = 1;
	for (int v : gr[u])
	{
		if (v == p)
			continue;
		if (dfs(v, u, gr, color))
		{
			if (ok == 0)
				path.push_back(u);
			if (path[0] == u)
				ok = 1;
			return true;
		}
	}
	return false;

}

int main()
{
    int n;
    cin >> n;
    graph gr(n);
    gr.resize(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
	vll color(n);
	bool ok = dfs(0, 0, gr, color);

	reverse(path.begin(), path.end());
	path.pop_back();
	sort(path.begin(), path.end());
	for (int i : path)
	{
		cout << i+1 << " ";
	}
}