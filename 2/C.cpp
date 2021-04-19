#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
	long long N;
	cin >> N;
	vector<long long> v(N);
	long long X, Y, x;
	for (long long i = 0; i < N; i++)
	{
		cin >> x;
		v[i] = x;
	}
	while (cin >> X >> Y) {
		if (X == 0 && Y == 0) {
			break;
		}
		for (long long i = 0; i < Y - (Y+X+1)/2 + 1; i++)
		{
			swap(v[i + X-1], v[Y -1 - i]);
		}
	}
	
	for (long long c : v) {
		cout << c << ' ';
	}
}
