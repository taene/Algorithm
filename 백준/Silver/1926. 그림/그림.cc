#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[504][504];
int visited[504][504];
queue<pair<int, int>> q;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int cnt, mx;

int bfs(int y, int x)
{
    q.push({y, x});
    visited[y][x] = 1;
    int token = 1;

    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] || !arr[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[here.first][here.second] + 1;
            token++;
        }
    }

    return token;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && arr[i][j])
            {
                cnt++;
                mx = max(mx, bfs(i, j));
            }
        }
    }
    cout << cnt << '\n' << mx;

    return 0;
}
