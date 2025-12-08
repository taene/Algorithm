#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, A, cnt;
int weight = 500;
bool visited[10];
vector<int> v;
vector<int> ret;

void dfs()
{
    for (auto i : ret)
    {
        if (weight < 500)
            return;
    }

    if (ret.size() == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            ret.push_back(v[i]);
            weight += (v[i] - k);
            dfs();
            weight -= (v[i] - k);
            ret.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> A;
        v.push_back(A);
    }
    dfs();
    cout << cnt;

    return 0;
}
