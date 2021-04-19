#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back
# define M_PI           3.14159265358979323846
struct vector3d {
	ll x = 0, y = 0, z = 0;
};
vector3d operator+(vector3d a, vector3d b)
{
	return { a.x + b.x, a.y + b.y, a.z + b.z };
}
vector3d operator-(vector3d a, vector3d b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}
vector3d operator*(vector3d a, ll n)
{
	return { a.x * n, a.y * n, a.z * n };
}
vector3d operator*(ll n, vector3d a)
{
	return a * n;
}

ll dot(vector3d a, vector3d b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

/*vector3d cross3d(vector3d a, vector3d b)
{
	return { a.y * b.z - a.z * b.y, };
}*/

double length(vector3d a)
{
	return sqrt(dot(a, a));
}
double distance(vector3d a, vector3d b)
{
	return length(a - b);
}

bool compare_pair(vector3d a, vector3d b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}
ll cross(vector3d a, vector3d b)
{
	return a.x * b.y - a.y * b.x;
}
bool compare_polar(vector3d a, vector3d b)
{
	return cross(a, b) > 0;
}

double distancetoline(vector3d a, vector3d b, vector3d p)
{
	double area = abs(cross(b - a, p - a));
	double h = distance(a, b);
	return area / h;
}
double distancetoray(vector3d a, vector3d b, vector3d p)
{
	if (dot(b - a, p - a) > 0)
		return distancetoline(a, b, p);
	return distance(p, a);
}
double distancetosegment(vector3d a, vector3d b, vector3d p)
{
	if (dot(b - a, p - a) < 0)
		return distance(p, a);
	if (dot(a - b, p - b) < 0)
		return distance(p, b);
	return distancetoline(a, b, p);
}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cout.precision(9);
	int n;
	cin >> n;
	ll x0,y0,x1,y1,x2,y2;
	vector3d p1, p2;
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		p1 = { x1 - x0, y1 - y0, 0 };
		p2 = { x2 - x0, y2 - y0, 0 };
		ans = dot(p1, p2) / length(p1);
		ans /= length(p2);
		cout << acos(ans) << '\n';

	}

}