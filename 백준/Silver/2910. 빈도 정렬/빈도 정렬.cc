#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, c;
map<int, int> mp_cnt;
map<int, int> mp_idx;
vector<pair<int, int>> ret;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return mp_idx[a.first] < mp_idx[b.first];
	else
		return a.second > b.second;
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
		mp_cnt[temp]++;

		if (mp_idx.find(temp) == mp_idx.end())
			mp_idx[temp] = i;
	}

	for (auto it : mp_cnt)
	{
		ret.push_back({ it.first, it.second });
	}

	sort(ret.begin(), ret.end(), cmp);

	for (auto it : ret)
	{
		for (int i = 0; i < it.second; i++)
			cout << it.first << ' ';
	}

	return 0;
}