#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n;
int visited[61][61][61];
int hp[3];
int adj[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3},
};

struct T
{
    int x, y, z;
};

queue<T> q;

int solve(int x, int y, int z)
{
    visited[x][y][z] = 1;
    q.push({x, y, z});

    while (q.size())
    {
        T t = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = max(0, t.x - adj[i][0]);
            int ny = max(0, t.y - adj[i][1]);
            int nz = max(0, t.z - adj[i][2]);

            if (visited[nx][ny][nz]) continue;
            if (nx == 0 && ny == 0 && nz == 0)
                return visited[t.x][t.y][t.z];

            visited[nx][ny][nz] = visited[t.x][t.y][t.z] + 1;
            q.push({nx, ny, nz});
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> hp[i];
    }
    cout << solve(hp[0], hp[1], hp[2]);

    return 0;
}
