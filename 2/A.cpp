#include <iostream>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	long long N;
	cin >> N;
	long long sum = 0;
	long long x;
	for (long long i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
	}
	cout << sum;
}