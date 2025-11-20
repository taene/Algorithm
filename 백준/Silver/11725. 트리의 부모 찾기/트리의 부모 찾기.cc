#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100004];
bool visited[100004];
int parents[100004];

void dfs(int here)
{
    visited[here] = true;

    for (auto i : v[here])
    {
        if (!visited[i])
        {
            parents[i] = here;
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);

    for (int i = 2; i <= n; ++i)
    {
        cout << parents[i] << '\n';
    }

    return 0;
}
