### 첫번째 풀이 (오답)
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, ret;
char adj[1000][1000];
bool visited[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
pair<int, int> jihoon;
vector<pair<int, int>> exitLocation;
queue<pair<int, int>> fire;

bool move(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx]) continue;
        if (adj[ny][nx] == '.')
        {
            jihoon = {ny, nx};
            return true;
        }
    }

    return false;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'J')
                jihoon = {i, j};
            if (adj[i][j] == 'F')
                fire.push({i, j});
            if (adj[i][j] == '.'
                && (i == 0 || j == 0 || i == r - 1 || j == c - 1))
                exitLocation.push_back({i, j});
        }
    }

    while (fire.size())
    {
        for (auto& i : exitLocation)
        {
            if (jihoon == i)
            {
                cout << (ret + 1);
                return 0;
            }
        }

        pair<int, int> temp = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = temp.first + dy[i];
            int nx = temp.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (adj[ny][nx] == '#') continue;

            adj[ny][nx] = 'F';
            fire.push({ny, nx});
        }

        if (!move(jihoon.first, jihoon.second))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        else
        {
            ret++;
        }
    }

    return 0;
}
```
