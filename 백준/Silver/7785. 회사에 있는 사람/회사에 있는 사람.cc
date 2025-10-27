#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> mp;
    vector<string> v;
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

    for (auto temp : mp)
    {
        if (temp.second)
        {
            v.push_back(temp.first);
        }
    }
    sort(v.begin(), v.end(), greater<string>());
    for (auto temp : v)
    {
        cout << temp << '\n';
    }

    return 0;
}
