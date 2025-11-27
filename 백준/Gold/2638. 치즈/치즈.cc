#include <iostream>

using namespace std;

int n, m;
int arr[100][100];
bool visited[100][100];
int cnt[100][100];
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
        if (arr[ny][nx] == 1)
        {
            cnt[ny][nx]++;
            continue;
        }
        if (arr[ny][nx] == 0 && !visited[ny][nx])
            dfs(ny, nx);
    }
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

    while (true)
    {
        bool flag = false;
        fill(&visited[0][0], &visited[0][0] + 100 * 100, false);
        fill(&cnt[0][0], &cnt[0][0] + 100 * 100, 0);

        dfs(0, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (arr[i][j] == 1 && cnt[i][j] >= 2)
                {
                    arr[i][j] = 0;
                    flag = true;
                }
            }
        }

        if (!flag)
            break;

        ret++;
    }
    cout << ret;

    return 0;
}
