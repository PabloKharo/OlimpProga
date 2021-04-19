#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	long long left = 0, right = 0, n = pow(10,15), length = 1;
	long long a, b, right2;
	char t;
	while (cin >> a >> t >> b) {
		left += a;
		right += b;
	}
	left += right / n;
	right %= n;
	right2 = right;
	while (right2 /= 10)
		length++;
	cout << left << '.' << string(15 - length, '0') << right << '\n';
}