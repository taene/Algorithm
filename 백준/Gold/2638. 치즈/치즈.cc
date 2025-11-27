#include <iostream>

using namespace std;

int n, m;
char arr[100][100];
bool visited[100][100];
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
        if (arr[ny][nx] == '1' && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            continue;
        }
        if (arr[ny][nx] == '1' && visited[ny][nx])
        {
            arr[ny][nx] = 'c';
            continue;
        }
        if (arr[ny][nx] == '0' && !visited[ny][nx])
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
            char temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    while (true)
    {
        bool flag = false;
        fill(&visited[0][0], &visited[0][0] + 100 * 100, false);

        dfs(0, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (arr[i][j] == 'c')
                {
                    arr[i][j] = '0';
                    flag = true;
                }
            }
        }

        if (!flag)
            break;
        else
            ret++;
    }
    cout << ret;

    return 0;
}
