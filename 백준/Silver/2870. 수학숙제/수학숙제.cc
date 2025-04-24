#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string buf, temp;
vector<string> ret;

void deleteZero()
{
	while (temp.size() && temp.front() == '0')
	{
		temp.erase(temp.begin());
	}

	if (temp.empty())
		temp = "0";

	ret.push_back(temp);
	temp = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--)
	{
		cin >> buf;

		for (int i = 0; i < buf.length(); i++)
		{
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				temp += buf[i];
			}
			else if (temp.size())
			{
				deleteZero();
			}
		}

		if (temp.size())
			deleteZero();
	}

	sort(ret.begin(), ret.end(), cmp);
	for (string it : ret)
		cout << it << '\n';

	return 0;
}