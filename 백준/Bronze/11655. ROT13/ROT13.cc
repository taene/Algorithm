#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				int k = (int)(s[i] + 13);
				if (k > 'Z')
					k -= 26;
				s[i] = (char)k;
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				int k = (int)(s[i] + 13);
				if (k > 'z')
					k -= 26;
				s[i] = (char)k;
			}
		}

		cout << s;
		return 0;
	}

	return 0;
}