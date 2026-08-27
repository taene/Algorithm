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
1. 1분 동안에 현재 큐에 들어있는 모든 불이 4방향으로 퍼져야 하고, 지훈이도 1분동안 갈 수 있는 모든 경우의 수를 탐색해야 한다. (시간 동기화 필요)
2. 지훈이가 최단 거리를 보장하고 모든 길을 동시에 탐색하기 위해 -> bfs로 구현해야 한다.
3. 불과 지훈이의 로직을 분리해야 한다. (하나의 루프에서 동시에 처리하지 말자)   
   3-1. 불 bfs를 전체적으로 먼저 돌려서, 맵의 각 길마다 '불이 몇분뒤에 도착하는지'를 기록하자.   
   3-2. 지훈이의 이동 bfs를 이후에 돌려서, 미리 만들어둔 불 도달 시간(fireVisited)와 비교해서 지훈이가 더 일찍 도착할 수 있는 칸으로 이동하자.   
   3-3. 불이 하나도 없을때도 고려하자. (예외처리)   

### 마지막 풀이
```cpp
#include <iostream>
#include <queue>
using namespace std;

int r, c;
char adj[1000][1000];
int jihoonVisited[1000][1000];
int fireVisited[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> jihoonLocation;
queue<pair<int, int>> fireLocation;

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> adj[i][j];

            if (adj[i][j] == 'F')
            {
                fireLocation.push({i, j});
                fireVisited[i][j] = 1;
            }
            else if (adj[i][j] == 'J')
            {
                jihoonLocation.push({i, j});
                jihoonVisited[i][j] = 1;
            }
        }
    }

    while (fireLocation.size())
    {
        pair<int, int> f = fireLocation.front();
        fireLocation.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = f.first + dy[i];
            int nx = f.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (fireVisited[ny][nx]) continue;
            if (adj[ny][nx] == '#') continue;

            fireVisited[ny][nx] = fireVisited[f.first][f.second] + 1;
            fireLocation.push({ny, nx});
        }
    }

    while (jihoonLocation.size())
    {
        pair<int, int> j = jihoonLocation.front();
        jihoonLocation.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = j.first + dy[i];
            int nx = j.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
            {
                cout << jihoonVisited[j.first][j.second];
                return 0;
            }
            if (jihoonVisited[ny][nx]) continue;
            if (adj[ny][nx] == '#') continue;

            if (fireVisited[ny][nx] == 0
                || fireVisited[ny][nx] > jihoonVisited[j.first][j.second] + 1)
            {
                jihoonVisited[ny][nx] = jihoonVisited[j.first][j.second] + 1;
                jihoonLocation.push({ny, nx});
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
```
