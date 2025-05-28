#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int temp = x;
    int sum = 0;
    while(temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    
    return (x % sum == 0);
}