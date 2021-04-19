#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
//#define sort(x) sort(x.begin(), x.end())
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
	int n;
	cin >> n;
	ll sum1 = 0, sum2 = 0;
	vector<vector3d> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}
	for (int i = 1; i < n; i++)
	{
		sum1 += v[i].x * v[i - 1].y;
		sum2 += v[i].y * v[i - 1].x;
	}
	sum1 += v[0].x * v[n - 1].y;
	sum2 += v[0].y * v[n - 1].x;
	double d = (sum1 - sum2)/ 2.0;
	if (d >= 0)
		cout << d;
	else
		cout << -d;

}