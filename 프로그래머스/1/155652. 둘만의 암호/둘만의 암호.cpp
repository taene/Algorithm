#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    bool isSkips[26];
    fill(isSkips, isSkips+26, false);
    for(int i=0; i<skip.size(); i++)
    {
        isSkips[static_cast<int>(skip[i]-'a')] = true;
    }
    
    for(int i=0; i<s.size(); i++)
    {
        int counting = 0;
        char curChar = s[i];
        while(counting < index)
        {
            curChar++;
            
            if(curChar>'z')
                curChar='a';
            
            if(!isSkips[static_cast<int>(curChar-'a')])
            {
                counting++;
            }
        }
        
        answer+=curChar;
    }
    
    return answer;
}