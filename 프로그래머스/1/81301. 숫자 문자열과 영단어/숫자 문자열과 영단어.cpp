#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string s) {
    long long answer = 0;
    string t="";
    
    vector<string> num;
    num.push_back("zero");
    num.push_back("one");
    num.push_back("two");
    num.push_back("three");
    num.push_back("four");
    num.push_back("five");
    num.push_back("six");
    num.push_back("seven");
    num.push_back("eight");
    num.push_back("nine");
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            answer+=static_cast<int>(s[i]-'0');
            answer*=10;
        }
        else
        {
            t+=(s[i]);
            for(int j=0; j<num.size(); j++)
            {
                if(t == num[j])
                {
                    answer+=j;
                    answer*=10;
                    t="";
                }
            }
        }
    }
    answer/=10;
    
    return answer;
}