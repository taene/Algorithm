#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
bool visited[25][25];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret;
vector<int> cnt;

int dfs(int y, int x)
{
    int token = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
        if (visited[ny][nx] == true || arr[ny][nx] == 0) continue;

        token += dfs(ny, nx);
    }
    
    return token;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = temp[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] == false && arr[i][j] == 1)
            {
                cnt.push_back(dfs(i, j));
                ret++;
            }
        }
    }

    cout << ret << '\n';
    sort(cnt.begin(), cnt.end());
    for (auto i : cnt)
    {
        cout << i << '\n';
    }

    return 0;
}
