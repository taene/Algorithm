#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> countNum(10,0);
    
    for(auto& i:score)
    {
        countNum[i]++;
    }
    
    for(int i=countNum.size()-1; i>0; i--)
    {
        if(countNum[i]!=0)
        {
            answer += i * m * (countNum[i]/m);
            countNum[i-1] += countNum[i] % m;
        }
    }
    
    return answer;
}