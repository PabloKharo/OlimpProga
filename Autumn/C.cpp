#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define sortr(x) sort(x.rbegin(), x.rend())
#define sort(x) sort(x.begin(), x.end())
#define PB push_back

void tabl(vector<char> c, bool& ok)
{
	switch (c[0])
	{
		case 'U':
			switch (c[1])
			{
				case 'U':
					switch (c[2])
					{
					case 'U':
					case 'C':
						cout << 'F';
						break;
					case 'A':
					case 'G':
						cout << 'L';
						break;
					}
					break;
				case 'C':
					switch (c[2])
					{
					case 'U':
					case 'C':
					case 'A':
					case 'G':
						cout << 'S';
						break;
					}
					break;
				case 'A':
					switch (c[2])
					{
					case 'U':
					case 'C':
						cout << 'Y';
						break;
					case 'A':
					case 'G':
						ok = false;
						break;
					}
					break;
				case 'G':
					switch (c[2])
					{
					case 'U':
					case 'C':
						cout << 'C';
						break;
					case 'A':
						ok = false;
						break;
					case 'G':
						cout << 'W';
						break;
					}
					break;

			}
			break;
		case 'C':
			switch (c[1])
			{
			case 'U':
				cout << 'L';
				break;
			case 'C':
				cout << 'P';
				break;
			case 'A':
				switch (c[2])
				{
				case 'U':
				case 'C':
					cout << 'H';
					break;
				case 'A':
				case 'G':
					cout << 'Q';
					break;
				}
				break;
			case 'G':
				cout << 'R';
				break;

			}
			break;
		case 'A':
			switch (c[1])
			{
			case 'U':
				switch (c[2])
				{
				case 'U':
				case 'C':
				case 'A':
					cout << 'I';
					break;
				case 'G':
					cout << 'M';
					break;
				}
				break;
			case 'C':
				switch (c[2])
				{
				case 'U':
				case 'C':
				case 'A':
				case 'G':
					cout << 'T';
					break;
				}
				break;
			case 'A':
				switch (c[2])
				{
				case 'U':
				case 'C':
					cout << 'N';
					break;
				case 'A':
				case 'G':
					cout << 'K';
					break;
				}
				break;
			case 'G':
				switch (c[2])
				{
				case 'U':
				case 'C':
					cout << 'S';
					break;
				case 'A':
				case 'G':
					cout << 'R';
					break;
				}
				break;
			}
			break;
		case 'G':
			switch (c[1])
			{
			case 'U':
				switch (c[2])
				{
				case 'U':
				case 'C':
				case 'A':
				case 'G':
					cout << 'V';
					break;
				}
				break;
			case 'C':
				switch (c[2])
				{
				case 'U':
				case 'C':
				case 'A':
				case 'G':
					cout << 'A';
					break;
				}
				break;
			case 'A':
				switch (c[2])
				{
				case 'U':
				case 'C':
					cout << 'D';
					break;
				case 'A':
				case 'G':
					cout << 'E';
					break;
				}
				break;
			case 'G':
				switch (c[2])
				{
				case 'U':
				case 'C':
				case 'A':
				case 'G':
					cout << 'G';
					break;
				}
				break;
			}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	string s;
	cin >> s;
	vector<char> c(3);
	char ch;
	bool ok = true;
	for (int i = 0; i < s.length() && ok == true; i++)
	{
		c[i%3] = s[i];
		if (((i + 1) % 3) == 0)
			tabl(c, ok);
	}

}