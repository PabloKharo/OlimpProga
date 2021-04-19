#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vll = vector<long long>;
 
struct Priority {
	ll distance, vertex;
};
struct Edge {
	ll to, w;
};
bool operator< (Priority lhs, Priority rhs)
{
	return lhs.distance > rhs.distance;
}
 
 
int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
 
	ll n, m;
	cin >> n >> m;
	vector<vector<Edge>> edges(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back(Edge{ v,w });
		edges[v].push_back(Edge{ u,w });
	}
	vll distances(n, 1000000000000);
	vll relaxed(n, 0);
	distances[n-1] = 0;
 
	priority_queue<Priority> pq;
	pq.push(Priority{ 0, n-1 });
	vll parents(n, -1);
	while (!pq.empty())
	{
		Priority u = pq.top();
		pq.pop();
		if (relaxed[u.vertex])
			continue;
		relaxed[u.vertex] = 1;
 
		for (Edge& e : edges[u.vertex])
		{
			if (distances[e.to] > distances[u.vertex] + e.w)
			{
				distances[e.to] = distances[u.vertex] + e.w;
				parents[e.to] = u.vertex;
				pq.push(Priority{ distances[e.to], e.to });
			}
		}
	}
 
	vll path;
	bool ok = true;
	for (ll v = 0; v != n - 1; v = parents[v])
	{
		if (parents[v] == -1)
		{
			ok = false;
			break;
		}
		path.push_back(v);
	}
	path.push_back(n-1);
 
	if (ok)
	{
		for (ll c : path)
		{
			c++;
			cout << c << " ";
		}
	}
	else
		cout << "-1";
 
}