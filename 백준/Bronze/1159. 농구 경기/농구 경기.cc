#include <iostream>
using namespace std;

int a[26];
string s;
string ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		a[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
			ans += (i + 'a');
	}

	if (ans.length())
		cout << ans;
	else
		cout << "PREDAJA";

	return 0;
}