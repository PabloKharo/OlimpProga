#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

char checkPodstr(string& s, int l, string& pods)
{
	int k = 0, m = 0;
	while(k != s.length() && m != l)
	{
		if (s[k] == pods[m])
			m++;
		k++;
	}

	if (m != l)
		return '1';
	return '0';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, l;
	string s, pods;
	cin >> n >> s >> m;
	string ans = "";

	for (int i = 0; i < m; i++)
	{
		cin >> l >> pods;
		ans = ans + checkPodstr(s, l, pods);
	}

	cout << ans;
}

