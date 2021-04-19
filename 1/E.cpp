#include <iostream>
 
using namespace std;
 
int main()
{
    int D, X, Y;
	cin >> D;
	cin >> X >> Y;
 
	if (X * X + Y * Y <= D * D)
		cout << "YES";
	else
		cout << "NO";
 