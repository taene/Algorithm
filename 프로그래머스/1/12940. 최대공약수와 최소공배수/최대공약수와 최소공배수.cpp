#include <string>
#include <vector>

using namespace std;

int ret1(int n, int m)
{
    if(n>m)
    {
        int temp;
        temp=n;
        n=m;
        m=temp;
    }
    
    int ret = 0;
    for(int i=1; i<=n; i++)
    {
        if(n%i==0 && m%i==0) ret = i;
    }
    return ret;
}

int ret2(int n, int m, int mx)
{
    n/=mx;
    m/=mx;
    return n*m*mx;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int mx = ret1(n,m);
    answer.push_back(mx);
    answer.push_back(ret2(n,m,mx));
    return answer;
}