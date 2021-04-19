#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
	long long N;
	cin >> N;
	vector<long long> v(N);
	long long count = 1;
	for (long long i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	for (long long i = 1; i < N; i++)
	{
		if (v[i] != v[i - 1])
			count++;
	}
	cout << count;
 
}