#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<int> sortInt;
    for(char& idx : s)
    {
        if(idx != ' ')
        {
            temp += idx;
        }
        else
        {
            sortInt.push_back(stoi(temp));
            temp.clear();
        }
    }
    
    if(!temp.empty())
    {
        sortInt.push_back(stoi(temp));
    }
    
    sort(sortInt.begin(), sortInt.end());
    answer += to_string(sortInt.front()) + " " + to_string(sortInt.back());
    return answer;
}