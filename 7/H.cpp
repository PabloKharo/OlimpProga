#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


struct segment { long long l, r; };
struct event {
	long long pos, type;
};

bool operator<(event lhs, event rhs)
{
	if (lhs.pos != rhs.pos)
		return lhs.pos < rhs.pos;
	return lhs.type > rhs.type;
}

int main()
{
	int N;
	cin >> N;
	vector<segment> segments(N);
	for (int i = 0; i < N; i++)
	{
		cin >> segments[i].l >> segments[i].r;
	}
	vector<event> events;
	long long ans = 0;
	long long current = 0;

	for (int i = 0; i < N; i++)
	{
		events.push_back(event{ segments[i].l, 1 });
		events.push_back(event{ segments[i].r, -1 });
	}
	sort(events.begin(), events.end());

	for (int i = 0; i < 2 * N; i++)
	{
		if (current != 0)
			ans += events[i].pos - events[i - 1].pos;
		else
			ans++;
		current += events[i].type;
	}
	cout << ans;
}

