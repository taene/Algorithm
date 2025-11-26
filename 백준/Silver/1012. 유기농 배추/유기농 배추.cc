#include <iostream>

using namespace std;

int m, n, k;
int arr[50][50];
bool visited[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret;

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] == true || arr[ny][nx] == 0) continue;

        dfs(ny, nx);
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
        ret = 0;
        fill(&arr[0][0], &arr[49][50], 0);
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

        cin >> m >> n >> k;
        for (int i = 0; i < k; ++i)
        {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!visited[i][j] && arr[i][j] == 1)
                {
                    ret++;
                    dfs(i, j);
                }
            }
        }
        cout << ret << '\n';
    }

    return 0;
}
