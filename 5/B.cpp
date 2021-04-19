#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
 
using namespace std;
 
 
int main()
{
	string s;
	cin >> s;
 
	long long r = 0;
	int k = 2;
	int mod = 97;
	if ((int(s[0]) - '0') == 0)
		r = 0;
	else if ((int(s[0]) - '0') * 10 + (int(s[1]) - '0') < 97 && s.length() <= 2)
		r = -1;
	else if ((int(s[0]) - '0') * 10 + (int(s[1]) - '0') < 97)
	{
		r = ((int(s[0]) - '0') * 100 + (int(s[1]) - '0') * 10 + (int(s[2]) - '0')) % mod;
		k++;
	}
	else
		r = ((int(s[0]) - '0') * 10 + (int(s[1]) - '0')) % mod;
 
	for (long long i = k; i < s.length(); i++)
	{
		r = (r * 10 + (int(s[i]) - '0')) % mod;
	}
	if (r == 0)
		cout << "YES";
	else
		cout << "NO";
 
}