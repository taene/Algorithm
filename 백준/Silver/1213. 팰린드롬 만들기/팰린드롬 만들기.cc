#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string name, temp, result;
int cnt[26];
int oddNum, oddIdx;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> name;
	sort(name.begin(), name.end());
	for (auto i : name)
		cnt[i - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] && cnt[i] % 2 == 1)
		{
			oddNum++;
			oddIdx = i;
		}
	}

	if (oddNum >= 2)
		cout << "I'm Sorry Hansoo" << '\n';
	else
	{
		if (oddNum)
			result += (oddIdx + 'A');

		for (int i = 25; i >= 0; i--)
		{
			if (cnt[i])
			{
				int half = cnt[i] / 2;
				string s(half, char(i + 'A'));
				result = s + result + s;
			}
		}

		cout << result << '\n';
	}


	return 0;
}