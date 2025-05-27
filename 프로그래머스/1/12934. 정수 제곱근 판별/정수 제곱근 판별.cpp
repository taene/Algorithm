#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    int k = sqrt(n);
    if(pow(k,2)==n) return pow(k+1,2);
    else return -1;
    
}