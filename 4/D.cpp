#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
 
 
int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sort(v[i].begin(), v[i].end());
	}
 
	int ans = n;
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++)
	{
		if (v[i] == v[i - 1])
			ans--;
	}
	cout << ans;
}