#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, log;
        cin >> name >> log;
        if (log == "enter")
        {
            mp[name]++;
        }
        else
        {
            mp[name]--;
        }
    }

    for (auto it = mp.rbegin(); it != mp.rend(); ++it)
    {
        if (it->second)
        {
            cout << it->first << '\n';
        }
    }

    return 0;
}
