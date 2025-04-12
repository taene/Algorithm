#include <iostream>
using namespace std;

string name, result;
int cnt[26];
int oddNum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> name;

	for (auto i : name)
		cnt[i - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		// 홀수표현: cnt[i] & 1 (비트연산자)
		if (cnt[i] && cnt[i] % 2 == 1)
		{
			result += (i + 'A');
			oddNum++;
		}
	}

	if (oddNum >= 2)
		cout << "I'm Sorry Hansoo" << '\n';
	else
	{
		for (int i = 25; i >= 0; i--)
		{
			if (cnt[i])
			{
				int half = cnt[i] / 2;
				string temp(half, char(i + 'A'));
				result = temp + result + temp;
			}
		}

		cout << result << '\n';
	}

	return 0;
}