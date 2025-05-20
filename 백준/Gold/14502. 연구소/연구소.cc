#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int adj[8][8];
bool visited[8][8];
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ret;

void vir(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx]) continue;
		if (adj[ny][nx] == 1) continue;

		vir(ny, nx);
	}
	return;
}

int solve()
{
	fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
	for (pair<int, int> i : virus)
	{
		//visited[i.first][i.second] = 1;
		vir(i.first, i.second);
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (adj[i][j] == 2 && !visited[i][j])
				vir(i, j);
		}
	}*/

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (adj[i][j] == 0 && !visited[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> adj[i][j];
			if (adj[i][j] == 2) virus.push_back({ i,j });
			if (adj[i][j] == 0) wall.push_back({ i,j });
		}
	}

	for (int i = 0; i < wall.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				adj[wall[i].first][wall[i].second] = 1;
				adj[wall[j].first][wall[j].second] = 1;
				adj[wall[k].first][wall[k].second] = 1;
				
				ret = max(ret, solve());

				adj[wall[i].first][wall[i].second] = 0;
				adj[wall[j].first][wall[j].second] = 0;
				adj[wall[k].first][wall[k].second] = 0;
			}
		}
	}
	cout << ret;

	return 0;
}