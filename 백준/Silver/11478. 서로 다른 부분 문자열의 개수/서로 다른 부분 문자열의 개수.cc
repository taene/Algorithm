#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    set<string> st;
    cin >> s;
    for (size_t i = 0; i < s.size(); ++i)
    {
        for (size_t len = 1; len <= s.size() - i; ++len)
        {
            string temp = s.substr(i, len);
            st.insert(temp);
        }
    }
    cout<<st.size();

    return 0;
}
