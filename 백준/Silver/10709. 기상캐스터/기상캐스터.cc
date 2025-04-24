#include <iostream>
using namespace std;

int h, w, k;
char temp[100][100];
int ret[100][100];
bool check = false;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	fill(&ret[0][0], &ret[0][0] + 100 * 100, -1);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> temp[i][j];
			if (temp[i][j] == 'c')
				ret[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++)
	{
		check = false;
		for (int j = 0; j < w; j++)
		{
			if (temp[i][j] == 'c')
			{
				check = true;
				k = 0;
			}
			else if (check)
			{
				ret[i][j] = ++k;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}