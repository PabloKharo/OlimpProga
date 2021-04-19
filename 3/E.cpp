#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<char> v;
	char skob;
	bool ok = true;
	v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> skob;

		switch (skob)
		{
		case '(':
			v.push_back(1);
			break;
		case '[':
			v.push_back(2);
			break;
		case '{':
			v.push_back(3);
			break;
		case ')':
			if (v.back() != 1)
				ok = false;
			v.pop_back();
			break;
		case ']':
			if (v.back() != 2)
				ok = false;
			v.pop_back();
			break;
		case '}':
			if (v.back() != 3)
				ok = false;
			v.pop_back();
			break;
		}

		if (!ok)
			break;
	}

	if (ok && v.size() == 1)
		cout << "Ja";
	else
		cout << "Nein";

}

