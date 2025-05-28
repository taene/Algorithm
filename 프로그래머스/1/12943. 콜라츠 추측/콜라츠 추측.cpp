#include <string>
#include <vector>

using namespace std;

long long& ret(long long& num)
{
    num = (num&1) ? num*3+1 : num/2;
    return num;
}

int solution(int num) {
    int cnt = 0;
    long long k = static_cast<long long>(num);
    
    if(num == 1)
    {
        return 0;
    }
    else
    {
        while(true)
        {
            if(cnt >= 500) return -1;
            ret(k);
            cnt++;
            if(k == 1) break;
        }
    }
    
    return cnt;
}