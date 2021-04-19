#include <iostream>
 
using namespace std;
 
int main()
{
	int Hs, Ms, Hl, Ml, Hb, Mb, N;
	cin >> Hs >> Ms;
	cin >> Hl >> Ml;
	cin >> Hb >> Mb;
	cin >> N;
 
	Hs = Hs + N * Hl + (N-1) * Hb;
	
    
	Ms = Ms + N * Ml + (N-1) * Mb;
	while (Ms >= 60) {
		Ms = Ms - 60;
		Hs = Hs + 1;
	}
	if(Hs >= 24)
		Hs = Hs % 24;
 
 
	cout << Hs <<' '<< Ms;
 
}