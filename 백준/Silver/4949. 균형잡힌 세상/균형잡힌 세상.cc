#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool chk(string s)
{
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == '[') st.push(s[i]);
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }

    if (st.empty()) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string s;
        getline(cin, s, '.');
        cin.ignore();

        if (s == "") break;

        if (chk(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
