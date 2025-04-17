#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int ya, xa, yb, xb, cnt;
vector<int> ret;
int adj[100][100];
bool visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x)
{
    cnt++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (adj[ny][nx]) continue;
        if (visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;

    while (k--)
    {
        cin >> xa >> ya;
        cin >> xb >> yb;

        for (int i = ya; i < yb; i++)
        {
            for (int j = xa; j < xb; j++)
            {
                adj[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!adj[i][j] && !visited[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ret.push_back(cnt);
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (int it : ret)
    {
        cout << it << ' ';
    }

    return 0;
}