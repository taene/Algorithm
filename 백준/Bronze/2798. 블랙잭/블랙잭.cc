#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int temp = arr[i] + arr[j] + arr[k];
                if (temp <= m)
                {
                    ret = max(ret, temp);
                }
            }
        }
    }
    cout << ret;

    return 0;
}
