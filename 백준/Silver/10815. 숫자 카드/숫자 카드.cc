#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, bool> mp;
    int n, m;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        mp[temp]=true;
    }

    cin>>m;
    for (int i=0; i<m; i++)
    {
        int temp;
        cin>>temp;
        if (mp[temp])
        {
            cout<<1<<' ';
        }
        else
        {
            cout<<0<<' ';
        }
    }

    return 0;
}
