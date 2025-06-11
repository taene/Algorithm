#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> ret;
    
    for(int i=0; i<s.size(); i++)
    {
        auto it = ret.find(s[i]);
        if(it == ret.end())
        {
            ret[s[i]]=i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - it->second);
            ret[s[i]]=i;
        }
    }
    
    return answer;
}