#include <iostream>
using namespace std;

int a, b, c;
int arr[102];
int sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = x; j < y; j++)
		{
			arr[j]++;
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		if (arr[i] == 0) continue;
		if (arr[i] == 1)
			sum += a;
		if (arr[i] == 2)
			sum += b * 2;
		if (arr[i] == 3)
			sum += c * 3;
	}

	cout << sum;

	return 0;
}