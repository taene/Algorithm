#include <iostream>
#include <vector>

using namespace std;

vector<int> v[104];
bool visited[104];
int a, b;
int mn = -1;

void dfs(int here, int cnt)
{
    visited[here] = true;

    if (here == b)
    {
        if (mn == -1 || cnt < mn)
        {
            mn = cnt;
        }
        return;
    }

    for (auto i : v[here])
    {
        if (!visited[i])
        {
            dfs(i, cnt + 1);
        }
    }

    visited[here] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(a, 0);
    cout << mn;

    return 0;
}
