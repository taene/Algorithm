#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, c;
map<int, pair<int, int>> mp;	// key, {count, index}

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
	return a.second.first > b.second.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (mp.find(temp) != mp.end())
		{
			mp[temp].first++;
		}
		else
			mp.insert({ temp,{1,i} });
	}

	vector<pair<int, pair<int, int>>> v(mp.begin(), mp.end());

	sort(v.begin(), v.end(), cmp);

	for (auto it : v)
	{
		int cnt = it.second.first;
		while (cnt--)
		{
			cout << it.first << ' ';
		}
	}

	return 0;
}