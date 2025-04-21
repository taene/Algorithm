#include <iostream>
using namespace std;

string S;
int a[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		a[S[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++)
		cout << a[i] << ' ';

	return 0;
}