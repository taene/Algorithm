#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

void dfs()
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

    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs();

    return 0;
}
