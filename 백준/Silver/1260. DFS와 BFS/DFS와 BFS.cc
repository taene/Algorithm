#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> arr(1004);
bool visited[1004];
queue<int> q;

void dfs(int here)
{
    visited[here] = true;
    cout << here << ' ';

    for (auto i : arr[here])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int here)
{
    q.push(here);
    visited[here] = true;

    while (q.size())
    {
        int qFront = q.front();

        for (auto i : arr[qFront])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
        cout << qFront << ' ';
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; ++i)
    {
        int y, x;
        cin >> y >> x;
        arr[y].push_back(x);
        arr[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(v);
    cout << '\n';
    fill(&visited[0], &visited[1004], false);
    bfs(v);

    return 0;
}
