#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//структура для координаты вектора
struct vector3d {
	ll x = 0, y = 0, z = 0;
};

// перегрузка оператора -
vector3d operator-(vector3d a, vector3d b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

// скалярное произведение
ll dot(vector3d a, vector3d b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// длина вектора
double length(vector3d a)
{
	return sqrt(dot(a, a));
}

// расстояние между точками
double distance(vector3d a, vector3d b)
{
	return length(a - b);
}

// векторное произведение
ll cross(vector3d a, vector3d b)
{
	return a.x * b.y - a.y * b.x;
}

// расстояние до прямой
double distancetoline(vector3d a, vector3d b, vector3d p)
{
	// площадь между точкой и прямой
	double area = abs(cross(b - a, p - a));
	// расстояние между точками
	double h = distance(a, b);
	return area / h;
}

// расстояние до отрезка
double distancetosegment(vector3d a, vector3d b, vector3d p)
{
	// если отрезок расположен справа
	if (dot(b - a, p - a) < 0)
		return distance(p, a);
	// если отрезок расположен слева
	if (dot(a - b, p - b) < 0)
		return distance(p, b);
	// если точка между концами
	return distancetoline(a, b, p);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.precision(9);
	int n;
	cin >> n;
	vector3d A, P, Q;
	for (int i = 0; i < n; i++)
	{
		cin >> A.x >> A.y >> P.x >> P.y >> Q.x >> Q.y;
		cout << distancetosegment(P, Q, A) << '\n';
	}
}