#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string index = "";
    
    for(int i=0; i<seoul.size(); i++)
    {
        if(seoul[i]=="Kim")
            index = to_string(i);
    }
    
    answer += "김서방은 " + index + "에 있다";
    
    return answer;
}