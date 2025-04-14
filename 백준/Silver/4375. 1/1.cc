#include <iostream>
using namespace std;

int n, cnt, ret;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n)
	{
		cnt = 1;
		ret = 1;
		while (cnt % n)
		{
			cnt = (cnt * 10) % n + 1;
			ret++;
		}
		cout << ret << '\n';
	}

	return 0;
}