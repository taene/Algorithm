#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int i=3;
    if(n&1) return 2;
    else
    {
        while(true)
        {
            if(n%i==1) return i;
            i++;
        }
    }
    
    return answer;
}