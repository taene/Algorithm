#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    map<string, int> mp;
    cin >> s;
    for (size_t i = 0; i < s.size(); ++i)
    {
        for (size_t j = i; j < s.size(); ++j)
        {
            string temp = s.substr(i, s.size() - j);
            mp[temp]++;
        }
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        cnt++;
    }
    cout << cnt;

    return 0;
}
