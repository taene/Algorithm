#include <iostream>
#include <stack>
using namespace std;

string temp;
int n, result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--)
	{
		stack<char> st;

		cin >> temp;
		for (int i = 0; i < temp.size(); i++)
		{
			if (!st.empty() && temp[i] == st.top())
			{
				st.pop();
			}
			else if (st.empty() || st.top() != temp[i])
			{
				st.push(temp[i]);
			}
		}

		if (st.empty())
			result++;
	}
	cout << result;

	return 0;
}