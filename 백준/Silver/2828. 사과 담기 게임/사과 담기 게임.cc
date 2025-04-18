#include <iostream>
using namespace std;

int n, m, j, st, ed, ret;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> j;
	
	st = 1;
	ed = st + m - 1;

	while (j--)
	{
		int temp;
		cin >> temp;

		if (temp > ed)
		{
			ret += temp - ed;
			ed = temp;
			st = ed - m + 1;
		}
		else if (temp < st)
		{
			ret += st - temp;
			st = temp;
			ed = st + m - 1;
		}
	}
	cout << ret;

	return 0;
}