#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;

bool cmp(string a, string b)
{
    return a[t] == b[t] ? a < b : a[t] < b[t];
}

vector<string> solution(vector<string> strings, int n) {
    t = n;
    for(int i=0; i<strings.size(); i++)
    {
        sort(strings.begin(), strings.end(), cmp);
    }
    
    return strings;
}