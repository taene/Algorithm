#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    int k = sqrt(n);
    if(static_cast<long long>(k)*k==n) return static_cast<long long>(k+1)*(k+1);
    else return -1;
}