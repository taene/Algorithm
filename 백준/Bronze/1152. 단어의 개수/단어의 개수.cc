#include <iostream>
#include <string>
#include <istream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a;
	int k = 0;

	getline(cin, a);

	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			k++;
		}
	}
	
	if (a[a.length()-1] == ' ')
	{
		k--;
	}
	cout << k + 1;

	return 0;
}