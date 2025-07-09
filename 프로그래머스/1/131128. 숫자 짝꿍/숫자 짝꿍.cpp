#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int numX[10]={};
    int numY[10]={};
    
    for(int i=0; i<X.size(); i++)
    {
        numX[X[i]-'0']++;
    }
    for(int i=0; i<Y.size(); i++)
    {
        numY[Y[i]-'0']++;
    }
    
    for(int i=9; i>=0; i--)
    {
        if(i==0&&answer.empty()&&(numX[i]&&numY[i]))
        {
            return "0";
        }
        
        if(numX[i]!=0&&numY[i]!=0)
        {
            answer+=string(min(numX[i],numY[i]), i+'0');
        }
    }
    
    if(answer.empty())
        return "-1";
    
    return answer;
}