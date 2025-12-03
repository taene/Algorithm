#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> visited(100001, 0);

    q.push(n);
    visited[n] = 1;

    while (q.size())
    {
        int here = q.front();
        q.pop();

        for (auto next : {here - 1, here + 1, here * 2})
        {
            if (next < 0 || next > 100000) continue;
            if (visited[next]) continue;

            q.push(next);
            visited[next] = visited[here] + 1;
        }
    }
    cout << visited[k] - 1;

    return 0;
}
