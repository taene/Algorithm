#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int N, M;
int ret[10001];
int visited[10001];
vector<int> v[10001];

int dfs(int com)
{
	int cnt = 1;
	visited[com] = 1;

	for (auto it : v[com])
	{
		if (visited[it]) continue;
		cnt += dfs(it);
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	int mx = 0;
	for (int i = 1; i <= N; i++)
	{
		fill(&visited[0], &visited[0] + 10001, 0);
		ret[i] = dfs(i);
		//mx = max(mx, ret[i]);
		if (mx <= ret[i])
			mx = ret[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (mx == ret[i])
			cout << i << ' ';
	}

	return 0;
}