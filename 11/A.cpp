#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back

ll solve(int cur, vll& visited, ll total, int n, vector<vector<ll>>& c)
{
	bool end = true;
	for (int i = 0; i < n; i++)
	{
		end &= visited[i];
	}
	if(end) return total;
	ll result = pow(10,9);
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			ll result = min(result, solve(i, visited, total + c[cur][i], n, c));
			visited[i] = 0;
		}
	}
	return total;
}

int main()
{
	int n;
	cin >> n;
	vector<vll> c(n, vll(n));
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> c[i][k];
		}
	}
	vll visited(n);
	visited[0] = 1;
	ll result = solve(0, visited, 0, n, c);
	cout << result;


}