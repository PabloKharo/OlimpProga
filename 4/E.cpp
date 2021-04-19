#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	multiset<long long> mst;
	long long x, a,b;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mst.insert(x);
	}

	while (mst.size() > 1)
	{
		a = *mst.begin();	
		mst.erase(mst.begin());
		b = *mst.begin();
		mst.erase(mst.begin());
		mst.insert(a + b);
		cout << a << ' ' << b << '\n';
		cout << "Hello";
	}


}

