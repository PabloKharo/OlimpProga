#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> opas(n);
	int s, f;
	// считывание номеров опасных комнат.
	for (int i = 0; i < n; i++)
	{
		cin >> opas[i];
	}
	// для бинарного поиска необходимо отсортировать вектор
	sort(opas.begin(), opas.end());

	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++)
	{
		cin >> s >> f;
		if (s > f)
			swap(s, f);
		// бинарный поиск индекса первой ловушки
		auto lower = lower_bound(opas.begin(), opas.end(), s);
		// бинарный поиск индекса последней ловушки
		auto upper = lower_bound(lower, opas.end(), f);
		// разность - количество ловушек на пути 
		cout << upper - lower << '\n';
	}

}

