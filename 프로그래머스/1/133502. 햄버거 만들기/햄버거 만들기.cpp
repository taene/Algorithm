#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> ret = {1,2,3,1};
    vector<int> stacks;
    bool correct = false;
    
    for(int temp : ingredient)
    {
        stacks.push_back(temp);
        
        if(stacks.size()>=4)
        {
            for(int i=0; i<ret.size(); i++)
            {
                if(stacks[stacks.size()-ret.size()+i]==ret[i])
                {
                    correct=true;
                }
                else
                {
                    correct=false;
                    break;
                }
            }
            
            if(correct)
            {
                answer++;
                for(int i=0; i<ret.size(); i++)
                {
                    stacks.pop_back();
                }
            }
        }
    }
    
    return answer;
}