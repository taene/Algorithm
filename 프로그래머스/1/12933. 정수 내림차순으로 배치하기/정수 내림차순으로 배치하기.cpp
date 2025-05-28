#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int cmp(int a, int b)
{
    return a >= b;
}

long long solution(long long n) {
    long long answer = 0;
    
    do
    {
        v.push_back(n%10);
        n/=10;
    } while(n);
    
    sort(v.begin(),v.end(),cmp);
    
    string k;
    for(int i:v)
    {
        k+=to_string(i);
    }
    answer = stol(k);
    
    return answer;
}