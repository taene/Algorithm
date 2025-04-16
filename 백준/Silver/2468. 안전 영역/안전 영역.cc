#include <iostream>
using namespace std;

int n, height, cnt;
int ret = 1; // 아무 지역도 물에 안 잠겼을 때
int adj[100][100];
bool visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (adj[ny][nx] <= height) continue;
		if (visited[ny][nx]) continue;
		
		dfs(ny, nx);
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
			if (height <= adj[i][j])
				height = adj[i][j];
		}
	}

	while (height)
	{
		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
		cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (adj[i][j] > height && !visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
		height--;
	}
	cout << ret;

	return 0;
}