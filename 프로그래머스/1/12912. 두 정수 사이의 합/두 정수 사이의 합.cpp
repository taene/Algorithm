#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a==b)
    {
        return a;
    }
    else if(a<b)
    {
        while(a<=b)
        {
            answer+=a;
            a++;
        }
    }
    else
    {
        // a>b
        while(b<=a)
        {
            answer+=b;
            b++;
        }
    }
    
    return answer;
}