#include <iostream>

using namespace std;

int n, m, k;
int arr[100][100];
bool visited[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret;

int dfs(int y, int x)
{
    int token = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || arr[ny][nx] == 0) continue;

        token += dfs(ny, nx);
    }

    return token;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int y, x;
        cin >> y >> x;
        arr[y - 1][x - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] == false && arr[i][j] == 1)
            {
                ret = max(ret, dfs(i, j));
            }
        }
    }
    cout << ret;

    return 0;
}