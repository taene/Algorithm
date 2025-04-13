#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	vector<int> material(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> material[i];
	}
	sort(material.begin(), material.end());

	int start_index = 0;
	int end_index = N - 1;
	int cnt = 0;

	while (start_index < end_index)
	{
		if (material[start_index] + material[end_index] < M)
		{
			start_index++;
		}
		else if (material[start_index] + material[end_index] > M)
		{
			end_index--;
		}
		else if (material[start_index] + material[end_index] == M)
		{
			cnt++;
			end_index--;
		}
	}

	cout << cnt << '\n';

	return 0;
}