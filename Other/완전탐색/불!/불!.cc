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
