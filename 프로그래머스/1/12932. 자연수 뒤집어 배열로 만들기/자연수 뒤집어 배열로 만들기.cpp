#include <string>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string k = to_string(n);
    
    for(int i=k.size()-1; i>=0; i--)
    {
        answer.push_back((int)(k[i]-'0'));
    }

    return answer;
}