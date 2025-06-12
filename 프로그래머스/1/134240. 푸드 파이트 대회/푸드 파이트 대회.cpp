#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    string temp = "";
    for(int i=food.size()-1; i>=1; i--)
    {
        temp = "";
        if(food[i] >= 2)
        {
            int t = food[i]/2;
            while(t--)
            {
                temp+=to_string(i);
                answer+=to_string(i);
            }
        }
        answer=temp+answer;
    }
    
    return answer;
}