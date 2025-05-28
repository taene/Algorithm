#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string k = to_string(n);
    sort(k.begin(), k.end(), greater<char>());
    answer = stoll(k);
    
    return answer;
}