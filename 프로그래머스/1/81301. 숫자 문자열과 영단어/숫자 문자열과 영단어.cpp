#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string t="";
    
    vector<string> num = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            answer = answer*10 + static_cast<int>(s[i]-'0');
        }
        else
        {
            t+=(s[i]);
            for(int j=0; j<num.size(); j++)
            {
                if(t == num[j])
                {
                    answer= answer*10+j;
                    t="";
                }
            }
        }
    }
    
    return answer;
}