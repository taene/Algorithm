#include <iostream>
using namespace std;

string s;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e'
		|| c == 'i' || c == 'o' || c == 'u');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> s;
		if (s == "end") break;

		bool isaeiou = false;
		int vowelCnt = 0;	//모음
		int consonantCnt = 0;	//자음
		bool isContinuous = false;
		bool isSame = false;
		int prev = -1;

		for (int i = 0; i < s.size(); i++)
		{
			if (isVowel(s[i]))
			{
				isaeiou = true;
				vowelCnt++;
				consonantCnt = 0;
			}
			else
			{
				consonantCnt++;
				vowelCnt = 0;
			}

			if (vowelCnt == 3 || consonantCnt == 3)
				isContinuous = true;

			if (i >= 1&&s[i] == s[prev] && s[i] != 'e' && s[i] != 'o')
			{
				isSame = true;
			}

			prev = i;
		}
		if (isaeiou && !isContinuous && !isSame)
			cout << "<" << s << ">" << " is acceptable." << '\n';
		else
			cout << "<" << s << ">" << " is not acceptable." << '\n';
	}
	

	return 0;
}