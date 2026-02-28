#include <iostream>
#include <vector>
using namespace std;

int N, temp, root, removeNode;
vector<int> node[50];

int dfs(int searchNode)
{
	int ret = 0;
	int child = 0;
	for (auto i : node[searchNode])
	{
		if (i == removeNode)
			continue;

		ret += dfs(i);
		child++;
	}
	if (!child) return 1;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == -1)
			root = i;
		else
			node[temp].push_back(i);
	}

	cin >> removeNode;
	if (root == removeNode)
	{
		cout << 0 << '\n';
		return 0;
	}
	else
		cout << dfs(root) << '\n';

	return 0;
}