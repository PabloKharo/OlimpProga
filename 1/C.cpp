#include <iostream>
 
using namespace std;
 
int main()
{
    int A, B, C;
	cin >> A >> B >> C;
	if (A >= B && A >= C)
		cout << A;
	else if (B >= A && B >= C)
		cout << B;
	else if(C >= A && C >= B)
		cout << C;
}