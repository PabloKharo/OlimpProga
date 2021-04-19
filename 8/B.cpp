#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define ll long long
using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	string s, s1;
	cin >> s >> s1;
	if (s.length() < s1.length())
		swap(s1, s);
	vector<int> prew(s.length() + 1);
	vector<int> cur(s1.length() + 1);

	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 1; j <= s1.length(); j++)
		{
			if (s[i - 1] == s1[j - 1])
				cur[j] = prew[j - 1] + 1;
			cur[j] = max(cur[j], max(prew[j], cur[j - 1]));
		}	
		prew.swap(cur);
	}
	
	cout << prew[s1.length()];
}

