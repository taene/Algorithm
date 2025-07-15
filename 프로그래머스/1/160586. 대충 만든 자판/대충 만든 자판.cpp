#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int alphabets[26]={};
    for(int i=0; i<keymap.size(); i++)
    {
        for(int j=0; j<keymap[i].size(); j++)
        {
            if(alphabets[keymap[i][j]-'A'] != 0)
            {
                alphabets[keymap[i][j]-'A'] = min(j+1, alphabets[keymap[i][j]-'A']);
            }
            else
                alphabets[keymap[i][j]-'A'] = j+1;
        }
    }
    
    for(int i=0; i<targets.size(); i++)
    {
        int counting = 0;
        for(int j=0; j<targets[i].size(); j++)
        {
            if(alphabets[targets[i][j]-'A'] == 0)
            {
                answer.push_back(-1);
                counting = 0;
                break;
            }
            counting+=alphabets[targets[i][j]-'A'];
        }
        if(counting!=0)
            answer.push_back(counting);
    }
    
    return answer;
}