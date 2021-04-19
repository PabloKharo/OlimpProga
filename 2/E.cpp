#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
	long long K = pow(10, 9) + 7;
	long long N;
	long long S = 1;
	cin >> N;
	if (N == 0) {
		cout << 1;
		exit(0);
	}
 
	for (long long i = 1; i <= N; i++)
	{
		S = S*i%K;
	}
	cout << S;
 
}