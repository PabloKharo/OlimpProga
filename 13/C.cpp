#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<long long>>;
using ll = long long;
using vll = vector<long long>;

vll path;
graph gr;
vll used;

// поиск в глубину
void dfs(int u, int f)
{
	// если посещали, то пропустить
	if (used[u])
		return;
	used[u] = 1;
	path.push_back(u);
	// если вершина - родители, пропустить
	if (u == f)
		return;
	// пройти по соседним вершинам
	for (int v : gr[u])
	{
		dfs(v, f);
		return;
	}
	path.pop_back();
}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);

	// считывание данных
	int n, m, s, f;
	cin >> n >> m >> s >> f;
	s--;
	f--;
	gr.resize(n);
	used.resize(n);
	// считывание графа
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	// поиск в глубину
	dfs(s, f);

	// если нет пути, то вывести -1
	if (path.size() == 0)
		cout << "-1";
	else 
	{
		// вывести путь
		for (int i : path)
		{
			cout << i + 1 << " ";
		}
	}
	
}