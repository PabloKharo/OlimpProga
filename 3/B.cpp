#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
	long long N;
	cin >> N;
	vector<long long> v(N);
 
	for (long long i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (long long c : v)
	{
		cout << c << ' ';
	}
}