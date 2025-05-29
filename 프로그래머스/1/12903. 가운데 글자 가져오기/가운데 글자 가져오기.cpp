#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size()&1) answer = s.substr(s.size()>>1, 1);
    else answer = s.substr((s.size()>>1) - 1, 2);
    
    return answer;
}