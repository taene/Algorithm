#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> adj;

void dfs(int y, int x, int n)
{
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (adj[i][j] != adj[y][x])
			{
				cout << '(';
				dfs(y, x, n / 2);
				dfs(y, x + (n / 2), n / 2);
				dfs(y + (n / 2), x, n / 2);
				dfs(y + (n / 2), x + (n / 2), n / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << adj[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string k;
		cin >> k;
		adj.push_back(k);
	}

	dfs(0, 0, n);

	return 0;
}