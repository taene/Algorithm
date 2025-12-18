#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, temp, ret;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < n; ++i)
    {
        v[i] += v[i - 1];
    }

    for (auto i : v)
    {
        ret += i;
    }
    cout << ret;

    return 0;
}
