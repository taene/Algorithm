#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> m;
	string s;
	int a, b;
	cin >> a >> b;
	while (a--)
	{
		cin >> s;
		m[s]++;
	}
	while (b--)
	{
		cin >> s;
		m[s]++;
	}
	
	int count = 0;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second > 1)
		{
			count++;
		}
	}
	cout << count << '\n';

	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second > 1)
		{
			cout << it->first << '\n';
		}
	}
}