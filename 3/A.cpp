#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vector3d
{
	string n;
	int s;
	int p;
};

bool operator<(vector3d ls, vector3d rs)
{
	if (ls.s != rs.s)
		return ls.s > rs.s;
	if (ls.p != rs.p)
		return ls.p < rs.p;
	return ls.n > rs.n;

}

int main()
{
	int N;
	cin >> N;
	vector<vector3d> v3d(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v3d[i].n;
		cin >> v3d[i].s;
		cin >> v3d[i].p;
	}

	sort(v3d.begin(), v3d.end());

	for (vector3d c : v3d)
	{
		cout << c.n << '\n';
	}
}