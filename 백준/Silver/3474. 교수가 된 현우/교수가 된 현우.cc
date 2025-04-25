#include <iostream>
using namespace std;

int t, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		int ret = 0;

		for (int i = 5; i <= n; i *= 5)
		{
			ret += n / i;
		}

		cout << ret << '\n';
	}

	return 0;
}