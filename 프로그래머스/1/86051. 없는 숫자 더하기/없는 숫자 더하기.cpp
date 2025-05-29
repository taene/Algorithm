#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int ret[10]={};
    
    for(auto i:numbers)
    {
        ret[i]=1;
    }
    for(int i=0; i<10; i++)
    {
        if(ret[i]==0) answer += i;
    }
    
    return answer;
}