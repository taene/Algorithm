#include <iostream>

using namespace std;

int n, k, temp;
int sum[100001];
int mx = -10000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}

	for (int i = k; i <= n; i++)
	{
		mx = max(mx, sum[i] - sum[i - k]);
	}
	cout << mx;

	return 0;
}