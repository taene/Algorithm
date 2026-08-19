#include <iostream>
#include <vector>
using namespace std;

int n, m;
int adj[100][100];
vector<pair<int, int>> allChicken;
vector<pair<int, int>> pickChicken;
int visited[100];

int chickenDistance()
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (adj[i][j] == 1)
            {
                int mn = INT_MAX;
                for (int k = 0; k < pickChicken.size(); ++k)
                {
                    int dis = abs(i - pickChicken[k].first)
                        + abs(j - pickChicken[k].second);
                    mn = min(mn, dis);
                }
                sum += mn;
            }
        }
    }
    return sum;
}

int pick(int start, int toPick, int mn)
{
    if (toPick == m)
    {
        mn = min(mn, chickenDistance());
        return mn;
    }

    for (int i = start + 1; i < allChicken.size(); ++i)
    {
        if (visited[i]) continue;
        pickChicken.push_back(allChicken[i]);
        visited[i] = 1;
        mn = pick(i, toPick + 1, mn);
        visited[i] = 0;
        pickChicken.pop_back();
    }

    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 2)
            {
                allChicken.push_back({i, j});
            }
        }
    }

    cout << pick(-1, 0, INT_MAX);

    return 0;
}
