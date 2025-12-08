#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool visited[10004];
vector<int> v1;
vector<int> v2;

void dfs()
{
    if (v2.size() == m)
    {
        for (auto i : v2)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (auto i : v1)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v2.push_back(i);
            dfs();
            v2.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    dfs();

    return 0;
}
