#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    return a == b ? static_cast<long long>(a) : (max(b-a, a-b) + 1) * (static_cast<long long>(a) + b) / 2;
}