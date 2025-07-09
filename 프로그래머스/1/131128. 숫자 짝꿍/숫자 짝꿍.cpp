#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int numX[10]={};
    int numY[10]={};
    
    for(char c : X)
    {
        numX[c - '0']++;
    }
    for(char c : Y)
    {
        numY[c - '0']++;
    }
    
    for(int i=9; i>=0; i--)
    {
        answer+=string(min(numX[i],numY[i]), i+'0');
    }
    
    if(answer.empty())
        return "-1";

    if (answer[0] == '0')
        return "0";
    
    return answer;
}