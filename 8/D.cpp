#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>prew(n+1);
	vector<int>cur(n+1);
	cin >> prew[0];
	for (int i = 2; i <= n; i++)
	{
		cin >> cur[0];
		// сидящий на самом левом месте может получить
		// только от сидящего на самом левом месте в предыдщуем ряду
		cur[0] += prew[0];
		for (int k = 2; k <= i; k++)
		{
			cin >> cur[k - 1];
			// каждому студенту передавать макисмально возможное 
			// количество конфет
			cur[k - 1] += max(prew[k - 1], prew[k-2]);		
		}
		// поменять местами вектора предыдущего и текущего рядов
		prew.swap(cur);

	}

	int mx = -1;
	// найти максимум конфет в ряду
	for (int i = 0; i < n; i++)
	{
		mx = max(prew[i], mx);
	}

	cout << mx;

}