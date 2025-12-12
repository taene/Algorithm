#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int cnt[26];
char arr[6][6];
bool visited[6][6];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int sy, int sx, int depth)
{
    if (sy == 0 && sx == C - 1)
    {
        cnt[depth]++;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = sy + dy[i];
        int nx = sx + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visited[ny][nx] || arr[ny][nx] == 'T') continue;

        visited[ny][nx] = true;
        dfs(ny, nx, depth + 1);
        visited[ny][nx] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> arr[i][j];
        }
    }
    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);
    cout << cnt[K];

    return 0;
}
