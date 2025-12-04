#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

void dfs(int here)
{
    if (v.size() == m)
    {
        for (auto i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = here; i <= n; ++i)
    {
        v.push_back(i);
        dfs(i + 1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(1);

    return 0;
}
