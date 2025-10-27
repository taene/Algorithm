#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	long long b;	//입력받은 정수

	cin >> a;
	vector<long long> plus(10000001);
	vector<long long> minus(10000001);
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (b < 0)
			minus[-b]++;
		else
			plus[b]++;
	}

	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (b < 0)
			cout << minus[-b] << " ";
		else
			cout << plus[b] << " ";
	}

}
