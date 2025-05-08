#include <iostream>
#include <string>
using namespace std;

int n, o, A, B, aSum, bSum;
string s, previous;

string print(int a) 
{
    string d = "00" + to_string(a / 60);
    string e = "00" + to_string(a % 60);
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int changeToInt(string a) 
{
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int& sum, string s) 
{
    sum += (changeToInt(s) - changeToInt(previous));
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> o >> s;

        if (A > B)
            go(aSum, s);
        else if (B > A)
            go(bSum, s);

        o == 1 ? A++ : B++;

        previous = s;
    }

    if (A > B)
        go(aSum, "48:00");
    else if (B > A)
        go(bSum, "48:00");

    cout << print(aSum) << "\n";
    cout << print(bSum) << "\n";
}