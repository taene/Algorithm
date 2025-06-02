#include <string>
#include <vector>

using namespace std;

vector<string> arr;

void split(string s)
{
    int start = 0;
    int end = 0;
    
    while(s.find(' ', start) != string::npos)
    {
        end = s.find(' ', start);
        arr.push_back(s.substr(start, end-start));
        start = end + 1;
    }
    arr.push_back(s.substr(start));
}

string solution(string s) {
    string answer = "";
    
    split(s);
    
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            if(!(j&1)) arr[i][j] = toupper(arr[i][j]);
            else arr[i][j] = tolower(arr[i][j]);
            answer+=(arr[i][j]);
        }
        if(i<arr.size()-1)
            answer+=" ";
    }
    
    return answer;
}