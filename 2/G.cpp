#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int N, k;
	cin >> N;
	long long x, min, max, cmin,cmax;
	vector<long long> v(N);
	vector< long long> mins;
	vector<long long> maxs;
 
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v[i] = x;
	}
	max = v[0];
	min = v[0];
	if (N == 1) 
	{
		mins.push_back(1);
		maxs.push_back(1);
		cmin = 1;
		cmax = 1;
	}
	else {
		for (int i = 0; i < N; i++)
		{
			k = i + 1;
			if (i == 0 && v[i] < v[i + 1])
				mins.push_back(k);
 
			else if (i == 0 && v[i] > v[i + 1])
				maxs.push_back(k);
 
			else if (i == N - 1 && v[i] < v[i - 1])
				mins.push_back(k);
 
			else if (i == N - 1 && v[i] > v[i - 1])
				maxs.push_back(k);
 
			else if (v[i] < v[i - 1] && v[i] < v[i + 1])
				mins.push_back(k);
 
			else if (v[i] > v[i - 1] && v[i] > v[i + 1])
				maxs.push_back(k);
 
			if (v[i] <= min)
			{
				min = v[i];
				cmin = k;
			}
			if (v[i] >= max)
			{
				max = v[i];
				cmax = k;
			}
		}
	}
	cout << mins.size();
 
	for (long long c : mins)
	{
		cout << ' ' << c;
	}
	cout << '\n' << maxs.size();
 
	for (long long c : maxs)
	{
		cout << ' ' << c;
	}
	cout <<'\n' << cmin << ' ' << cmax;
 
}