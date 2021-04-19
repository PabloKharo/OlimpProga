#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
	long long N, M;
	cin >> N >> M;
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;
	long long count = 0;
	for (long long i = 0; i < N; i++)
	{
		if (s1.substr(i, M) == s2.substr(0, M) )
		{
			count++;
		}		
	}
 
	cout << count;
}