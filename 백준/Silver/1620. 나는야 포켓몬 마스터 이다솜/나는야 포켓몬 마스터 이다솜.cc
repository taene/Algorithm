#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n, m;
string temp;
map<string, int> pm;
vector<string> name;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		pm.insert({ temp,i });
		name.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9')
		{
			cout << name[stoi(temp) - 1] << '\n';
		}
		else
		{
			cout << pm[temp] << '\n';
		}
	}

	return 0;
}