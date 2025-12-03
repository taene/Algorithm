#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, ret;
int arr[104][104];
int visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct T
{
    int x;
    int y;
};

int bfs(int sy, int sx)
{
    queue<T> q;

    q.push({sy, sx});
    visited[sy][sx] = 1;
    int token = 1;

    while (q.size())
    {
        T here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            T next = {here.y + dy[i], here.x + dx[i]};

            if (next.x < 0 || next.y < 0 || next.y >= n || next.x >= m) continue;
            if (visited[next.y][next.x] || !arr[next.y][next.x]) continue;

            q.push({next.y, next.x});
            visited[next.y][next.x] = visited[here.y][here.x] + 1;
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

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int r, c;
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && arr[i][j])
            {
                ret = max(ret, bfs(i, j));
            }
        }
    }
    cout << ret;

    return 0;
}
