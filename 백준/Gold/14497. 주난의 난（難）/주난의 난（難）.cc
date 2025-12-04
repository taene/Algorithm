#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x2, y2;
char arr[304][304];
int visited[304][304];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Point
{
    int y;
    int x;
};

void bfs(int sy, int sx)
{
    queue<Point> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (arr[y2][x2] != '0')
    {
        queue<Point> temp;

        while (q.size())
        {
            Point here = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                Point next = {here.y + dy[i], here.x + dx[i]};

                if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= m) continue;
                if (visited[next.y][next.x]) continue;
                if (arr[next.y][next.x] != '0')
                {
                    arr[next.y][next.x] = '0';
                    temp.push(next);
                    visited[next.y][next.x] = visited[here.y][here.x] + 1;
                }
                else
                {
                    q.push(next);
                    visited[next.y][next.x] = visited[here.y][here.x];
                }
            }
        }

        q = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1;
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--;
    x1--;
    y2--;
    x2--;

    for (int i = 0; i < n; ++i)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = st[j];
        }
    }

    bfs(y1, x1);
    cout << visited[y2][x2] - 1;

    return 0;
}
