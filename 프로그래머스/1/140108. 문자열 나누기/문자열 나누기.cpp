#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char firstChar=s[0];
    int counting[2]={}; // 0:firstCount, 1:not
    
    for(int i=0; i<s.size(); i++)
    {
        if(counting[0]==counting[1])
        {
            answer++;
            firstChar=s[i];
            counting[0]=0;
            counting[1]=0;
        }
        
        if(s[i]==firstChar)
            counting[0]++;
        else
            counting[1]++;
    }
    
    return answer;
}