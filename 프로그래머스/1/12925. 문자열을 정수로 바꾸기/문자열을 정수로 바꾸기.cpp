#include <string>
#include <vector>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    // 1
    /*
    if(s[0]=='-')
    {
        s=s.substr(1);
        answer -= stoi(s);
    }
    else
    {
        answer = stoi(s);
    }
    */
    
    // 2
    //answer = stoi(s);
    
    // 3
    answer = atoi(s.c_str());
    
    return answer;
}