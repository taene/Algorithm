#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        cout<<s.front()<<s.back()<<'\n';
    }
    
    return 0;
}
