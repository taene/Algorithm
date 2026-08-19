#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
char adj[50][50];
vector<pair<int, int>> ground;
vector<pair<int, int>> treasure;
bool visited1[50][50];
int visited2[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(pair<int, int> start, pair<int, int> end)
{
    fill(&visited2[0][0], &visited2[0][0] + 50 * 50, 0);

    queue<pair<int, int>> q;
    q.push(start);
    visited2[start.first][start.second] = 1;
    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited2[ny][nx]) continue;
            if (adj[ny][nx] == 'L')
            {
                visited2[ny][nx] = visited2[here.first][here.second] + 1;
                q.push({ny, nx});
            }
        }
    }

    return visited2[end.first][end.second] - 1;
}

int pick(int start, int toPick, int mx)
{
    if (toPick == 2)
    {
        mx = max(mx, bfs(treasure[0], treasure[1]));
        return mx;
    }

    for (int i = start + 1; i < ground.size(); ++i)
    {
        if (visited1[ground[i].first][ground[i].second]) continue;
        visited1[ground[i].first][ground[i].second] = true;
        treasure.push_back(ground[i]);
        mx = pick(i, toPick + 1, mx);
        treasure.pop_back();
        visited1[ground[i].first][ground[i].second] = false;
    }

    return mx;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'L')
            {
                ground.push_back({i, j});
            }
        }
    }

    cout << pick(-1, 0, -1);

    return 0;
}
