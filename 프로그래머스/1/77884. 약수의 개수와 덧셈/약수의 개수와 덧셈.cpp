#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int num=left; num<=right; num++)
    {
        int cnt = 0;
        for(int i=1; i<=num; i++)
        {
            if(num%i==0) cnt++;
        }
        cnt&1 ? answer-=num : answer+=num;
    }
    
    return answer;
}