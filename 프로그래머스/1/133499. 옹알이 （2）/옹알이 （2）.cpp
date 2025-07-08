#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> can = {"aya", "ye", "woo", "ma"};
    
    for(string b: babbling)
    {
        string temp = "";
        string before = "";
        for(int i=0; i<b.size(); i++)
        {
            temp+=b[i];
            
            for(int j=0; j<4; j++)
            {
                if(temp==can[j]&&temp!=before)
                {
                    before = temp;
                    temp.clear();
                    break;
                }
            }
        }
        
        if(temp.empty())
            answer++;
    }
    
    
    return answer;
}