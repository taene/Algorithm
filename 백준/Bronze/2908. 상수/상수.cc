#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    string retA, retB;
    for (auto it = a.rbegin(); it != a.rend(); ++it)
    {
        retA += *it;
    }
    for (auto it = b.rbegin(); it != b.rend(); ++it)
    {
        retB += *it;
    }
    
    if (retA >= retB)
    {
        cout << retA;
    }
    else
    {
        cout << retB;
    }

    return 0;
}
