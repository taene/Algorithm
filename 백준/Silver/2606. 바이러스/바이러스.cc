#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
bool chk[101] = {};

void dfs(int x, vector<int> graph[])
{
	chk[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!chk[y])
		{
			cnt++;
			dfs(y, graph);
		}
	}
}

int main()
{
	int computer;	//그래프 정점
	int linkLine;	//그래프 간선의 개수
	cin >> computer >> linkLine;

	vector<int> graph[101];

	while (linkLine--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, graph);
	cout << cnt;

	return 0;
}