### 풀이방법
```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, l, r, ret;
int a[50][50];
bool visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> v;

void dfs(int y, int x)
{
    visited[y][x] = true;
    v.push_back({y, x});

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;

        int diff = abs(a[y][x] - a[ny][nx]);
        if (diff < l || diff > r) continue;

        dfs(ny, nx);
    }
}

void setAvg()
{
    int avg = 0;
    for (auto& i : v)
    {
        avg += a[i.first][i.second];
    }
    avg /= v.size();

    for (auto& i : v)
    {
        a[i.first][i.second] = avg;
    }
}

bool check()
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                v.clear();
                dfs(i, j);
                if (v.size() > 1)
                {
                    setAvg();
                    flag = true;
                }
            }
        }
    }

    return flag;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

        if (!check())
            break;

        ret++;
    }

    cout << ret;

    return 0;
}
```

1. 모든 요소들에 대해 dfs를 진행해서 연합 영역 찾기
2. 방문처리와 함께 연합 국가들을 나타내는 벡터배열 v에 위치 담기
3. 각 연합의 평균을 내어 요소들 값 수정하기
4. 1~3 까지의 하나의 루프를 완료할 때마다 ret++하여 답 구하기
