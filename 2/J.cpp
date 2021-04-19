#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int check = 1, small = 0, x, y, x0, y0;

	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2) 
		swap(y1, y2);
	if (x3 > x4) 
		swap(x3, x4);
	if (y3 > y4) 
		swap(y3, y4);

	if (x1 > x4 || x2 < x3) 
		check = 0; 
	else 
		x = max(x1, x3);

	if (y1 > y4 || y2 < y3) 
		check = 0; 
	else 
		y = max(y1, y3);

	if (x1 > x4 || x2 < x3) 
		check = 0; 
	else 
		x0 = min(x2, x4);

	if (y1 > y4 || y2 < y3) 
		check = 0; 
	else 
		y0 = min(y2, y4);

	if (check == 1) 
		small = (x0 - x) * (y0 - y);
	cout << (x2 - x1) * (y2 - y1) + (x3 - x4) * (y3 - y4) - small;
}

