#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[101];
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });

	while (q.size())
	{
		pair<int, int> k = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = k.first + dy[i];
			int nx = k.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!adj[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			
			visited[ny][nx] = visited[k.first][k.second] + 1;
			q.push({ ny,nx });
		}
	}

	cout << visited[n - 1][m - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			adj[i].push_back((int)(temp[j] - '0'));
		}
	}

	bfs(0, 0);

	return 0;
}