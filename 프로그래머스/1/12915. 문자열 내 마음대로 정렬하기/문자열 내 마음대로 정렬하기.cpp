#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;

bool cmp(string a, string b)
{
    if(a[t]==b[t]) return a <= b;
    return a[t] < b[t];
}

vector<string> solution(vector<string> strings, int n) {
    t=n;
    for(int i=0; i<strings.size(); i++)
    {
        sort(strings.begin(), strings.end(), cmp);
    }
    
    return strings;
}