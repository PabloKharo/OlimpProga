#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
 
int solve(long long N) {
	vector<long long> v(N);
	long long x;
	long long count1 = 0;
	long long count = 0;
	for (long long i = 0; i < N; i++)
	{
		cin >> x;
		v[i] = x;
	}
	do {
		count1 = count;
		for (long long i = 0; i < N - 1; i++)
		{
			if (v[i] > v[i + 1]) {
				count++;
				swap(v[i], v[i + 1]);
			}
		}
 
	} while (count1 != count);
	return count;
}
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	long long N;
	vector<long long> k(T);
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		k[i] = solve(N);
		
	}
	for (long long c : k) {
		cout << c << '\n';
	}
}