#include <iostream>
#include <memory.h>
using namespace std;

bool arr[51][51] = { false };
bool visit[51][51] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int m, n, k;	//배추밭 가로, 세로, 개수

void dfs(int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (arr[ny][nx] == 1 && visit[ny][nx] == 0
			&& (ny >= 0 && ny < n) && (nx >= 0 && nx < m))
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 51; i++) 
		{
			memset(visit[i], 0, sizeof(bool) * (51));	//함수 메모리 초기화
			memset(arr[i], 0, sizeof(bool) * (51));
		}
		cin >> m >> n >> k;

		while (k--)
		{
			int x, y;	//배추 위치
			cin >> x >> y;
			arr[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}