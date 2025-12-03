#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ret;
char arr[51][51];
int visited[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct T
{
    int y;
    int x;
};

void bfs(int sy, int sx)
{
    queue<T> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size())
    {
        T here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            T next = {here.y + dy[i], here.x + dx[i]};

            if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= m) continue;
            if (visited[next.y][next.x] || arr[next.y][next.x] == 'W') continue;

            q.push({next});
            visited[next.y][next.x] = visited[here.y][here.x] + 1;
            ret = max(ret, visited[next.y][next.x]);
        }
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
        string st;
        cin >> st;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = st[j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 'L')
            {
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                bfs(i, j);
            }
        }
    }
    cout << ret - 1;

    return 0;
}
