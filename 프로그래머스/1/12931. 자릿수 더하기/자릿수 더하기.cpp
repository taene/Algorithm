#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(true)
    {
        if(n==0) break;
        int k = n%10;
        answer+=k;
        n/=10;
    }

    return answer;
}