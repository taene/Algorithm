#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    pair<int,int> minNum = {0, arr[0]};
    
    if(arr.size()==1)
    {
        answer.push_back(-1);
        return answer;
    }
    else
    {
        for(int i=0; i<arr.size(); i++)
        {
            if(minNum.second > arr[i])
            {
                minNum.second = arr[i];
                minNum.first = i;
            }
        }
        for(auto i:arr)
        {
            if(i!=minNum.second) answer.push_back(i);
        }
    }
    
    return answer;
}