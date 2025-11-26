#include <iostream>

using namespace std;

int n, m;
int arr[500][500];
bool visited[500][500];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int cnt, mx;

int dfs(int y, int x)
{
    int token = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] == true || arr[ny][nx] == 0) continue;

        token += dfs(ny, nx);
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
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] == false && arr[i][j] == 1)
            {
                cnt++;
                mx = max(mx, dfs(i, j));
            }
        }
    }

    cout << cnt << '\n' << mx;

    return 0;
}