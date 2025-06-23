#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    
    int counts[3]={};
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==first[i%first.size()]) counts[0]++;
        if(answers[i]==second[i%second.size()]) counts[1]++;
        if(answers[i]==third[i%third.size()]) counts[2]++;
    }
    
    int mx = 0;
    for(int i=0; i<3; i++)
    {
        if(mx<=counts[i])
        {
            mx = counts[i];
        }
    }
    
    for(int i=0; i<3; i++)
    {
        if(mx == counts[i]) answer.push_back(i+1);
    }
    
    return answer;
}