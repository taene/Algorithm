#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    for(int i=0; i<score.size(); i++)
    {
        temp.push_back(score[i]);
        sort(temp.begin(), temp.end());
        
        // vector::size()는 size_t(unsigned int)임
        int index = (static_cast<int>(temp.size()) - k) >= 0 ? static_cast<int>(temp.size()) - k : 0;
        answer.push_back(temp[index]);
    }
    
    return answer;
}