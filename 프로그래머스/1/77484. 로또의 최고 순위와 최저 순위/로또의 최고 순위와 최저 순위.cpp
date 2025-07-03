#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int win = 0;
    int zero = 0;
    for(int i : lottos)
    {
        if(i==0)
        {
            zero++;
            continue;
        }
        
        for(int j : win_nums)
        {
            if(i==j) 
                win++;
        }
    }
    
    !(win==0 && zero==0) ? answer.push_back(7-(win+zero)) : answer.push_back(6);
    win!=0 ? answer.push_back(7-win) : answer.push_back(6);
    
    return answer;
}