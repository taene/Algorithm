#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[10004];
bool visited[10004];
int ret[10004];

int dfs(int here)
{
    int sum = 1;
    visited[here] = true;

    for (auto k : v[here])
    {
        if (!visited[k])
        {
            sum += dfs(k);
        }
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        fill(visited, visited + 10004, 0);

        ret[i] = dfs(i);
        mx = max(mx, ret[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (mx == ret[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}
