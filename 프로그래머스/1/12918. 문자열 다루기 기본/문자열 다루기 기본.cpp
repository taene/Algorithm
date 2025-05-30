#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()==4 || s.size()==6)
    {
        for(auto i:s)
        {
            if(i>='0' && i<='9') answer=true; 
            else return false;
        }
    }
    else
        answer=false;
        
    return answer;
}