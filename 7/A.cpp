#include <iostream>
#include <algorithm>
#include <vector>
 
#include <cmath>
using namespace std;
 
 
 
int main()
{
	
	int n;
	cin >> n;
	vector<long long> numbers(n);
	vector<long long> sums(n + 1);
	sums[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		sums[i + 1] = sums[i] + numbers[i];
	}
 
	int q;
	cin >> q;
	int left, right;
	vector<long long> res(q);
	for (int i = 0; i < q; i++)
	{
		cin >> left >> right;
		res[i] = sums[right] - sums[left - 1];
	}
	for (long long c : res)
	{
		cout << c << '\n';
	}
	
}