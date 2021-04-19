#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
	long long N;
	long long S = 0;
	cin >> N;
	long long count = 0;
	vector<long long> v(2);
	v[0] = 1;
	v[1] = 1;
	if (N == 0) {
		cout << 0;
		exit(0);
	}
	if (N == 1) {
		cout << 1;
		exit(0);
	}
	if (N == 2) {
		cout << 2;
		exit(0);
	}
	for (long long i = 1; S < N; i++)
	{
		v.push_back(v[i] + v[i - 1]);
		S = v[i+1];
		count = i+2;
	}
	if (N != S) {
		count = -1;
	}
	cout << count;
}