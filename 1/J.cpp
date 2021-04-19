#include <iostream>
 
using namespace std;
 
int main()
{
	long long a, b;
	long long S;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	if (a == b)
		cout << a;
	else
	{
		S = (a+b)*(b-a+1) / 2;
		cout <<  S << endl;
	}
 
}
 