### 첫번째 풀이
```cpp
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
```
- 이 문제는 pick() 함수로 뽑은 2개의 보물 위치를 bfs를 통해 두 보물 사이의 최단 거리를 구하고, 그렇게 뽑은 최단 거리의 값을 리턴하여 pick() 함수에서 max()를 통해 가장 긴 최단거리의 값을 구하도록 풀었다.
- 그런데 풀면서 생각해보니, 굳이 조합으로 2개의 보물 위치를 뽑지 않고도, 모든 맵의 육지('L')에서 bfs를 돌리면 최단 거리의 배열들이 나오기 때문에 - 그 중에서 max 값을 가져오면 되는 것이 아닌가?
- 따라서 아래의 풀이로 마무리했다.

### 마지막 풀이
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char adj[50][50];
int visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(int startY, int startX)
{
    fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);

    queue<pair<int, int>> q;
    q.push({startY, startX});
    visited[startY][startX] = 1;

    int max_dist = 0;

    while (q.size())
    {
        pair<int, int> here = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (adj[ny][nx] == 'L')
            {
                visited[ny][nx] = visited[here.first][here.second] + 1;
                // 도달할 때마다 가장 큰 거리값을 갱신 (시작점이 1이므로 나중에 1을 뺌)
                max_dist = max(max_dist, visited[ny][nx]);
                q.push({ny, nx});
            }
        }
    }

    if (max_dist > 0)
    {
        return max_dist - 1;
    }
    
    return 0;
}

int main()
{
    cin >> n >> m;
    vector<pair<int, int>> ground;

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

    int result = 0;
    
    // 두 점을 뽑을 필요 없이, 모든 육지에서 각각 한 번씩만 BFS를 수행
    for (int i = 0; i < ground.size(); ++i)
    {
        result = max(result, bfs(ground[i].first, ground[i].second));
    }

    cout << result;

    return 0;
}
```
