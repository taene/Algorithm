#include <iostream>
#include <algorithm>
using namespace std;

string pel;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> pel;

	string tmp = pel;
	reverse(pel.begin(), pel.end());
	if (tmp == pel)
		cout << 1;
	else
		cout << 0;

	return 0;
}