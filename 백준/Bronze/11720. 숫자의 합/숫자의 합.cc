#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string a;
	int sum = 0;


	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		sum += a[i]-'0';	//숫자 그대로 쓰는거
	}


	cout << sum;
}