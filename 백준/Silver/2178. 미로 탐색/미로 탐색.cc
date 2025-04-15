#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, M;
int adj[100][100];
int visited[100][100];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });

	while (!q.empty())
	{
		int a, b;
		tie(a, b) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (!adj[ny][nx]) continue;

			visited[ny][nx] = visited[a][b] + 1;
			q.push({ ny,nx });
		}
	}

	cout << visited[N - 1][M - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			adj[i][j] = (int)(temp[j] - '0');
		}
	}
	bfs(0, 0);

	return 0;
}