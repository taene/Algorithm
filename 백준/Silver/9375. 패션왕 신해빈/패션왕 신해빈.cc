#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int t;
	int n;
	string a, b;

	cin >> t;

	while (t--)
	{
		map<string, int> m;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			m[b]++;
		}

		int answer = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second > 0)
			{
				answer *= iter->second + 1;
			}
		}
		cout << answer - 1 << '\n';
	}

	return 0;
}