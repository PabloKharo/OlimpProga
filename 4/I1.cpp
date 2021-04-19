#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	long long counts = 0;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		for (int k = i + 1; k < N; k++)
		{
			for (int m = k + 1; m < N; m++)
			{
				if ((v[i] + v[k]) > v[m])
					counts++;
				else
					break;
 
			}
		}
	}
	cout << counts;
 
 
 
}