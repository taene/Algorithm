#include <iostream>
#include <cstring>
using namespace std;

int main()
{	
	char s[101];	//알파벳 소문자 단어
	int k[26];	//알파벳 배열 a,b,c,d,...
	int p[26] = {};	//처음 등장하는 위치인지 체크

	for (int i = 0; i < 26; i++)	//배열k의 모든 원소 -1로 초기화
	{
		k[i] = -1;
	}

	cin >> s;

	for (int i = 0; i < strlen(s); i++)	//처음 등장하는 위치인지 아닌지 고려
	{
		if (p[s[i] - 'a'] == 0)	//해당 알파벳이 처음 등장했다면
		{
			k[s[i] - 'a'] = i;
			p[s[i] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << k[i] << " ";
	}

}