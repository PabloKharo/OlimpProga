#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	vector<long long> c(N);
	bool ok = true;
	for (int i = 0; i < N; i++)
	{
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < N-1; i++)
	{
		if (c[i + 1] != (c[i] + 1))
			ok = false;
	}
	if (ok == true)
		cout << "Deck looks good";
	else
		cout << "Scammed";
    
}