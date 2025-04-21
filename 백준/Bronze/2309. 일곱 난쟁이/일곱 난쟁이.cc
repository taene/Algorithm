#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++)
		cin >> a[i];

	int size = sizeof(a) / sizeof(a[0]);
	sort(a, a + size);

	do
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += a[i];

		if (sum == 100)
			break;
	} while (next_permutation(a, a + size));

	for (int i = 0; i < 7; i++)
		cout << a[i] << '\n';

	return 0;
}