#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int a = 0;
    int b = 0;
    for(int i=0; i<goal.size(); i++)
    {
        if(a<=cards1.size() && goal[i]==cards1[a])
        {
            a++;
        }
        else if(b<=cards2.size() && goal[i]==cards2[b])
        {
            b++;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}