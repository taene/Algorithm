#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, bool> mp;
    int n, m;
    int ret = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        mp[temp] = true;
    }
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        if (mp[temp])
        {
            ret++;
        }
    }

    cout << ret;

    return 0;
}
