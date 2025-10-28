#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> mp;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }

    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second == 1)
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
