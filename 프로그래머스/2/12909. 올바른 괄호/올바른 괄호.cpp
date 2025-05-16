#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<int> check;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
        {
            check.push(1);
        }
        else
        {
            if(check.empty())
            {
                return false;
            }
            check.pop();
        }
    }
    
    if(check.empty())
    {
        answer=true;
    }
    else
        answer=false;
    
    return answer;
}