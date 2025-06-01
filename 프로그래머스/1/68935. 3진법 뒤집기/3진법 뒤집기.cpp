#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string ret;

void sol(int n, int x)
{
    if(n==0) return;
    
    int k = pow(3,x);
    if(n>=k*2)
    {
        ret += "2";
        if(x==0) return;
        sol(n-(k*2), x-1);
    }
    else if(n>=k)
    {
        ret += "1";
        if(x==0) return;
        sol(n-k, x-1);
    }
    else
    {
        ret += "0";
        if(x==0) return;
        sol(n, x-1);
    }
}

int solution(int n) {
    int answer = 0;
    
    int x=0;
    for(int i=1; i<=n; i*=3) { x++; }
    x--;
    
    sol(n, x);
    
    reverse(ret.begin(), ret.end());
    
    int t=0;
    for(int i=ret.size()-1; i>=0; i--)
    {
        answer += pow(3,t++) * static_cast<int>(ret[i]-'0');
    }
    
    return answer;
}