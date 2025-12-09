#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k, temp;
vector<int> v;
vector<int> ret;

void dfs(int here)
{
    if (ret.size() == 6)
    {
        for (auto i : ret)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = here; i < v.size(); ++i)
    {
        ret.push_back(v[i]);
        dfs(i + 1);
        ret.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> k)
    {
        v.clear();
        if (k == 0) return 0;

        for (int i = 0; i < k; ++i)
        {
            cin >> temp;
            v.push_back(temp);
        }

        dfs(0);
        cout << '\n';
    }

    return 0;
}
