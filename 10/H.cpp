#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	// если у стола четная ширина и длина,
	// то выигрывает 2 игрок
	if (n % 2 != 0 && m % 2 != 0)
		cout << 2;
	else	
		cout << 1;

}