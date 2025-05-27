#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int i=3;
    while(true)
    {
        if(n%2==1)
        {
            answer = 2;
            return answer;
        }
        else
        {
            if(n%i==1)
            {
                answer=i;
                return answer;
            }
            i++;
        }
    }
    
    return answer;
}