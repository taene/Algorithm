#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = n / 5; i >= 0; --i)
    {
        int rest = n - (5 * i);
        if (rest % 3 == 0)
        {
            cnt = i + (rest / 3);
            break;
        }
    }
    cout << cnt;

    return 0;
}
