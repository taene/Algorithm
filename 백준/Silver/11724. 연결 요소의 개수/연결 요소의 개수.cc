#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1004];
bool visited[1004];
int ret;

void dfs(int here)
{
    visited[here] = true;

    for (auto i : v[here])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            ret++;
        }
    }
    cout << ret;

    return 0;
}
