#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

long long ToTenth(int a, string& s)
{
	int c;
	long long g = 0;
	long long apow = 1;
	for (long long i = s.length() -1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
			c = s[i] - '0';
		else
			c = s[i] - 'a' + 10;

		g += c * apow;
		apow *= a;

	}
	return g;

}

string ToAns(int b, long long& g)
{
	string part = "";
	int k;
	char c;
	if (g == 0)
		part = "0";

	while (g != 0)
	{
		k = g % b;
		if (k > 9)
			c = (char)(k + 'a' - 10);
		else
			c = (char)(k + '0');
		g /= b;
		part = c + part;
	}
	return part;



}


int main()
{
	int a, b;
	cin >> a >> b;

	string number;
	cin >> number;

	string ans;
	long long g;

	g = ToTenth(a, number);
	ans = ToAns(b, g);

	cout << ans;
}

