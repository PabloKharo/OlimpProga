#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
void Do(long long l, long long r)
{
	char c;
	long long m = (l + r) / 2;
	cout << m << endl;
	cout.flush();
	cin >> c;
 
	if (c == '>')
		r = m;
	else if (c == '<')
		l = m;
	else
		exit(0);
	Do(l, r);
}
 
int main()
{
	long long l, r;
	l = -1;
	r = pow(10, 9) + 1;
	Do(l, r);
 
}