#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    int temp = 5;
    for(int i=0; i<a-1; i++)
    {
        temp+=month[i];
    }
    temp+=b-1;
    
    return week[temp%7];
}
