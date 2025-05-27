#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for(auto i:numbers)
    {
        answer+=i;
    }
    answer/=numbers.size();
    
    return answer;
}