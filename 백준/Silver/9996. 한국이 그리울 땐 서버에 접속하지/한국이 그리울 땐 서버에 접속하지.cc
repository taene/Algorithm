#include <iostream>
using namespace std;

int N;
string pattern, temp;
string before, after;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> pattern;

	int pos = pattern.find('*');
	before = pattern.substr(0, pos);
	after = pattern.substr(pos + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		// 반례
		if (before.size() + after.size() > temp.size())
		{
			cout << "NE" << '\n';
		}
		else
		{
			if (before == temp.substr(0, before.size())
				&& after == temp.substr(temp.size() - after.size()))
			{
				cout << "DA" << '\n';
			}
			else
				cout << "NE" << '\n';
		}
	}

	return 0;
}