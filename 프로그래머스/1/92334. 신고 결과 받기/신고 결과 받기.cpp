#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, unordered_set<string>> result;
    
    unordered_map<string, int> id_list_map;
    for (int i = 0; i < id_list.size(); i++)
    {
        id_list_map[id_list[i]] = i;
    }
    
    for(int i=0; i<report.size(); i++)
    {
        auto end = report[i].find(' ');
        string value = report[i].substr(0, end - 0);
        string key = report[i].substr(end+1);
        
        result[key].insert(value);
    }
    
    for(const auto& temp : result)
    {
        if(temp.second.size()>=k)
        {
            for(const string& ret : temp.second)
            {
                answer[id_list_map[ret]]++;
            }
        }
    }
    
    return answer;
}