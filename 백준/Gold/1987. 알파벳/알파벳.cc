#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, ret;
char arr[24][24];
bool visited[26];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt)
{
    ret = max(ret, cnt);

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visited[arr[ny][nx] - 'A']) continue;

        visited[arr[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        visited[arr[ny][nx] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> arr[i][j];
        }
    }
    visited[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ret;

    return 0;
}
