#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string mel = "수박";
    bool isOdd = n&1;
    int k = n>>1;
    while(k--) answer+=mel;
    if(isOdd) answer+="수";
    
    return answer;
}