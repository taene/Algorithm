#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    /*
    for(int i=0; i<=n; i++)
    {
        if(i%2==0)
            answer+=i;
    }
    */
    
    // 등차수열의 합 공식: 항의 갯수 * (첫 항 + 막 항) / 2
    int count = n/2;
    answer = count*(2+count*2)/2;
    
    return answer;
}