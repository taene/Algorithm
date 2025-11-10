#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(),a.end());
    reverse(b.begin(), b.end());
    
    if (a >= b)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }

    return 0;
}
